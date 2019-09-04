"""
Get tags and generate the file prepostfunctions.c to all tags
"""

def gen_functions(tags, fw):
    fw.write('#include <stdio.h>\n')
    fw.write('#include <stdlib.h>\n')
    fw.write('#include "debug.h"\n\n')


    fw.write('typedef unsigned long long gomp_ull;\n')
    fw.write('typedef _Bool bool;\n')
    fw.write('typedef long TYPE;\n\n')
    fw.write('#define NUM_FUNCTIONS %d\n' % len(tags))
    fw.write('// Keep the partial counters.\n')
    fw.write('unsigned long int partial_count[NUM_FUNCTIONS];\n')
    fw.write('unsigned long int accum_count[NUM_FUNCTIONS];\n\n')

    fw.write('enum omp_idx_function {' + ','.join(['idx_' +
                                                tag.name for tag in tags]) + '} omp_idx_function;\n')

    fw.write('\n')
    fw.write('void print_results_csv_partial(void) {\n')
    fw.write('\tprintf("' + ', '.join(['Number of ' + tag.name for tag in tags]) + '");\n')
    fw.write('\tprintf("' + ', '.join(['%lu'] * len(tags)) + '", ') # end
    fw.write(', '.join('partial_count[idx_%s]' % tag.name for tag in tags)) # end
    fw.write(');\n')
    fw.write('}\n')

    fw.write('\n')
    fw.write('void print_results_csv_accum(void) {\n')
    fw.write('\tprintf("' + ', '.join(['Number of ' + tag.name for tag in tags]) + '");\n')
    fw.write('\tprintf("' + ', '.join(['%lu'] * len(tags)) + '", ') # end
    fw.write(', '.join('accum_count[idx_%s]' % tag.name for tag in tags)) # end=''
    fw.write(');\n')
    fw.write('}\n')

    fw.write('\n// HOOKS\n\n')

    for tag in tags:
        fw.write('%s PRE_%s %s {\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\tPRINT_FUNC_NAME;\n')
        fw.write('\tpartial_count[idx_%s]++;\n' % tag.name)
        fw.write('}\n\n')

        fw.write('%s POST_%s %s {\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\tPRINT_FUNC_NAME;\n')

        if tag.name == 'GOMP_parallel_end':
            fw.write('\tprint_results_csv_partial();\n')

            fw.write('\tint i;\n')
            fw.write('\tfor (i = 0; i < NUM_FUNCTIONS; i++) {\n')
            fw.write('\t\taccum_count[i] += partial_count[i];\n')
            fw.write('\t\tpartial_count[i] = 0;\n')
            fw.write('\t}\n')

            fw.write('\tprint_results_csv_accum();\n')

        fw.write('}\n\n')


    fw.write('\n///GENERATED %d FUNCTIONS' % len(tags))


def gen_prepostfunctions(tags, file_name):
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    #gen_header(file, fw)
    gen_functions(tags, fw)
    #gen_tail(file, fw)

    fw.close()
    print('OK')