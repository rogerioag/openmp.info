"""
Get tags and generate the file prepostdef.h to all tags
"""

def gen_prepostdef(tags):
    visited_files = []

    for tag in tags:
        if tag.file not in visited_files:
            print('\n/* %s */\n' % tag.file)
            visited_files.append(tag.file)

        print('%s PRE_%s %s;' % (tag.return_type, tag.name, tag.signature))
        print('%s POST_%s %s;' % (tag.return_type, tag.name, tag.signature))
        print('')

    print('\n\n///GENERATED %d FUNCTIONS' % len(tags))