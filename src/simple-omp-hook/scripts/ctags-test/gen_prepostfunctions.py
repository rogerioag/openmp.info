import parse_tag

tags = parse_tag.parse()

print('// Variables')
for tag in tags:
    print('int num_%s = 0;' % tag.name)

print('\n\n// print_results')
for tag in tags:
    print('printf("Number of %s: %%d\\n", num_%s);' % (tag.name, tag.name))

print('\n\n// HOOKS')

for tag in tags:
    print('%s PRE_%s %s {' % (tag.return_type, tag.name, tag.signature))
    print('\tPRINT_FUNC_NAME;')
    print('\tnum_%s++;' % (tag.name))
    print('}\n')

    print('%s POST_%s %s {' % (tag.return_type, tag.name, tag.signature))
    print('\tPRINT_FUNC_NAME;')
    print('}\n')


print('\n\n///GENERATED %d FUNCTIONS' % len(tags))
