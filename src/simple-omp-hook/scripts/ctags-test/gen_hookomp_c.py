"""
Get tags and generate the file hookomp.c to all tags
"""

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

    #gen_header(file, fw)
    gen_functions(tags, fw)
    #gen_tail(file, fw)

    fw.close()
    print('OK')