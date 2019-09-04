"""
Get tags and generate the file hookomp.h to all tags
"""

def gen_functions(tags, fw):
    visited_files = []

    for tag in tags:
        if tag.file not in visited_files:

            fw.write('\n/* %s */\n' % tag.file)

            visited_files.append(tag.file)

        fw.write('%s (*lib_%s) %s;' % (tag.return_type, tag.name, tag.signature))

    fw.write('\n\n// --------------------  END OF PART 1\n\n')

    visited_files.clear()

    for tag in tags:
        if tag.file not in visited_files:

            fw.write('\n/* %s */\n' % tag.file)

            visited_files.append(tag.file)

        fw.write('%s %s %s;' % (tag.return_type, tag.name, tag.signature))

    fw.write('\n\n///GENERATED %d FUNCTIONS' % len(tags))

def gen_hookomp_h(tags, file_name):
    # file writer
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    #gen_header(file, fw)
    gen_functions(tags, fw)
    #gen_tail(file, fw)

    fw.close()
    print('OK')