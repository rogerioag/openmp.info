"""
Get tags and generate the file hookomp.c to all tags
"""

# else, the file reader will be the pos_ppd
def gen_from_model(fw, pre=True):
    file_name = 'model/'
    file_name += 'pre_hkc' if pre else 'pos_hkc'
    file_name += '.c'

    try:
        model = open(file_name)

        for line in model.readlines():
            if line.startswith('//\\'):
                continue

            fw.write(line)
    except FileNotFoundError:
        pass

def gen_functions(tags, fw):
    visited_files = []

    for tag in tags:
        if tag.file not in visited_files:
            fw.write('/* ------------------------------------------------------------- */\n')
            fw.write('/* %s\n' % tag.file)
            fw.write('/* ------------------------------------------------------------- */\n\n')
            visited_files.append(tag.file)

        fw.write('%s %s %s {\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\tPRINT_FUNC_NAME;\n')
        fw.write('\tGET_RUNTIME_FUNCTION(lib_%s, "%s");\n' % (tag.name, tag.name))
        fw.write('\tTRACE("[hookomp]: Thread [%%lu] is executing %s.\\n", (unsigned long int)pthread_self());\n' % tag.name)
        fw.write('\tPRE_%s%s;\n' % (tag.name, tag.call))

        if tag.return_type == 'void':
            fw.write('\tlib_%s%s;\n' % (tag.name, tag.call))
        else:
            fw.write('\t%s ret = lib_%s%s;\n' % (tag.return_type, tag.name, tag.call))  

        fw.write('\tPOST_%s%s;\n' % (tag.name, tag.call))

        if tag.return_type != 'void':
            fw.write('\treturn ret;\n')

        fw.write('}\n\n')

    fw.write('\n///GENERATED %d FUNCTIONS' % len(tags))

def gen_hookomp_c(tags, file_name):
    # file writer
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    gen_from_model(fw, True)
    gen_functions(tags, fw)
    gen_from_model(fw, False)

    fw.close()
    print('OK')