"""
Get tags and generate the file prepostdef.h to all tags
"""

def gen_functions(tags, fw):
    visited_files = []

    for tag in tags:
        if tag.file not in visited_files:
            fw.write('/* %s */\n\n' % tag.file)
            visited_files.append(tag.file)

        fw.write('%s PRE_%s %s;\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('%s POST_%s %s;\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\n')

    fw.write('\n///GENERATED %d FUNCTIONS' % len(tags))

def gen_prepostdef(tags, file_name):
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    #gen_header(file, fw)
    gen_functions(tags, fw)
    #gen_tail(file, fw)

    fw.close()
    print('OK')