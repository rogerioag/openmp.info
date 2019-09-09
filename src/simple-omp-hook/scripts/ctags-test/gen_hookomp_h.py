"""
Get tags and generate the file hookomp.h to all tags
"""

def gen_from_model(fw, pre=True):
    file_name = 'model/'
    file_name += 'pre_hkh' if pre else 'pos_hkh'
    file_name += '.c'

    try:
        model = open(file_name)

        for line in model.readlines():
            if line.startswith('//\\'):
                continue

            fw.write(line)
    except FileNotFoundError:
        pass

def gen_def_inside(fw):
    """
        #ifdef __cplusplus
        extern "C"
        {
        #endif
    """
    fw.write('#ifdef __cplusplus\n')
    fw.write('extern "C"\n')
    fw.write('{\n')
    fw.write('#endif\n')

# Firstly, generate the pointer of functions
# after, generate the prototypes
def gen_part(tags, fw, line, line_end, identation=''):
    visited_files = []

    for tag in tags:
        if tag.file not in visited_files:
            fw.write('\n' + identation + '/* %s */\n\n' % tag.file)
            visited_files.append(tag.file)

        fw.write(identation + line % (tag.return_type, tag.name, tag.signature))

    fw.write(line_end)


def gen_functions(tags, fw):
    gen_part(tags, fw, '%s (*lib_%s) %s;\n', '\n\n// --------------------  END OF PART 1\n\n')
    gen_def_inside(fw)
    gen_part(tags, fw, '%s %s %s;\n', '\n\n///GENERATED %d FUNCTIONS' % len(tags), identation='    ')

def gen_hookomp_h(tags, file_name):
    # file writer
    fw = open(file_name, 'w')
    print('generate {} ...'.format(file_name), end='', flush=True)

    gen_from_model(fw, True)
    gen_functions(tags, fw)
    gen_from_model(fw, False)

    fw.close()
    print('OK')