"""
Get tags and generate the file prepostdef.h to all tags
"""

# if pre is True, the file reader will be the pre_ppd
# else, the file reader will be the pos_ppd
def gen_from_model(fw, pre=True):
    file_name = 'model/'
    file_name += 'pre_ppd' if pre else 'pos_ppd'
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
            fw.write('\t/* %s */\n\n' % tag.file)
            visited_files.append(tag.file)

        fw.write('\t%s PRE_%s %s;\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\t%s POST_%s %s;\n' % (tag.return_type, tag.name, tag.signature))
        fw.write('\n')

    fw.write('\n\t///GENERATED %d FUNCTIONS\n' % len(tags))

def gen_prepostdef(tags, file_name):
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    gen_from_model(fw, True)
    gen_functions(tags, fw)
    gen_from_model(fw, False)

    fw.close()
    print('OK')