"""
Get tags and generate the file prepostfunctions.c to all tags
"""

# this values should be generated dynamically
def gen_print_results_csv_partial(fw, tags):
    fw.write('\n')
    fw.write('void print_results_csv_partial(void) {\n')
    for tag in tags:
        fw.write('\tprint("{0}", partial_count[idx_{0}]);\n'.format(tag.name))
    fw.write('}\n\n')

# this values should be generated dynamically
def gen_print_results_csv_accum(fw, tags):
    fw.write('\n')
    fw.write('void print_results_csv_accum(void) {\n')
    for tag in tags:
        fw.write('\tprint("{0}", accum_count[idx_{0}]);\n'.format(tag.name))
    fw.write('}\n\n')

# this values cannot be in a file
# because they must be generated dynamically from the tags
def gen_dynamic_values(fw, tags):
    fw.write('#define NUM_FUNCTIONS %d\n' % len(tags))
    fw.write('// Keep the partial counters.\n')
    fw.write('unsigned long int partial_count[NUM_FUNCTIONS];\n')
    fw.write('unsigned long int accum_count[NUM_FUNCTIONS];\n\n')

    fw.write('enum omp_idx_function {' + ','.join(['\n\tidx_' +
                                                tag.name for tag in tags]) + '\n} omp_idx_function;\n\n')

# if pre is True, the file reader will be the pre_ppf
# else, the file reader will be the pos_ppf
def gen_from_model(fw, pre=True):
    file_name = 'model/'
    file_name += 'pre_ppf' if pre else 'pos_ppf'
    file_name += '.c'

    try:
        model = open(file_name)

        for line in model.readlines():
            if line.startswith('//\\'):
                continue

            fw.write(line)
    except FileNotFoundError:
        pass

def gen_functions(fw, tags):
    fw.write('\n// HOOKS\n\n')

    for tag in tags:
        fw.write('%s PRE_%s %s\n{\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\tPRINT_FUNC_NAME;\n')
        fw.write('\tpartial_count[idx_%s]++;\n' % tag.name)
        fw.write('}\n\n')

        fw.write('%s POST_%s %s \n{\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\tPRINT_FUNC_NAME;\n')

        if tag.name == 'GOMP_parallel_end':
            fw.write('\tprintf("\\n");\n')
            fw.write('\tprint_results_csv_partial();\n')

            fw.write('\tint i;\n')
            fw.write('\tfor (i = 0; i < NUM_FUNCTIONS; i++) {\n')
            fw.write('\t\taccum_count[i] += partial_count[i];\n')
            fw.write('\t\tpartial_count[i] = 0;\n')
            fw.write('\t}\n')

            # fw.write('\tprintf("\\n");\n')
            # fw.write('\tprint_results_csv_accum();\n')
            fw.write('\tprintf("\\n");\n')

        fw.write('}\n\n')


    fw.write('\n///GENERATED %d FUNCTIONS' % len(tags))


def gen_prepostfunctions(tags, file_name):
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    gen_from_model(fw, True)

    gen_dynamic_values(fw, tags)
    gen_print_results_csv_partial(fw, tags)
    gen_print_results_csv_accum(fw, tags)

    gen_functions(fw, tags)
    gen_from_model(fw, False)

    fw.close()
    print('OK')