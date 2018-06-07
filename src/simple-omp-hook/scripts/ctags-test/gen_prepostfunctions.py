import parse_tag

tags = parse_tag.parse()

print('#include <stdio.h>')
print('#include <stdlib.h>')
print('#include "debug.h"')


print('typedef unsigned long long gomp_ull;')
print('typedef _Bool bool;')
print('typedef long TYPE;')

print('// Variables')
for tag in tags:
    print('int num_%s = 0;' % tag.name)

print('\n\n// print_results')
print('void print_results(void) {')
for tag in tags:
    print('\tprintf("Number of %s: %%d\\n", num_%s);' % (tag.name, tag.name))
print('}')

print('\n\n// HOOKS')

for tag in tags:
    print('%s PRE_%s %s {' % (tag.return_type, tag.name, tag.signature))
    print('\tPRINT_FUNC_NAME;')
    print('\tnum_%s++;' % (tag.name))
    print('}\n')

    print('%s POST_%s %s {' % (tag.return_type, tag.name, tag.signature))
    print('\tPRINT_FUNC_NAME;')

    if tag.name == 'GOMP_parallel_end':
        print('\tprint_results();')

    print('}\n')


print('\n\n///GENERATED %d FUNCTIONS' % len(tags))
