"""
Get tags and generate the file prepostfunctions.c to all tags
"""

def gen_prepostfunctions(tags):
    print('#include <stdio.h>')
    print('#include <stdlib.h>')
    print('#include "debug.h"')


    print('typedef unsigned long long gomp_ull;')
    print('typedef _Bool bool;')
    print('typedef long TYPE;')
    print('#define NUM_FUNCTIONS %d' % len(tags))
    print('// Keep the partial counters.')
    print('unsigned long int partial_count[NUM_FUNCTIONS];')
    print('unsigned long int accum_count[NUM_FUNCTIONS];')

    print('enum omp_idx_function {' + ','.join(['idx_' +
                                                tag.name for tag in tags]) + '} omp_idx_function;')

    print('\n')
    print('void print_results_csv_partial(void) {')
    print(
        '\tprintf("' + ', '.join(['Number of ' + tag.name for tag in tags]) + '");')
    print('\tprintf("' + ', '.join(['%lu'] * len(tags)) + '", ', end='')
    print(', '.join('partial_count[idx_%s]' % tag.name for tag in tags), end='')
    print(');')
    print('}')

    print('\n')
    print('void print_results_csv_accum(void) {')
    print(
        '\tprintf("' + ', '.join(['Number of ' + tag.name for tag in tags]) + '");')
    print('\tprintf("' + ', '.join(['%lu'] * len(tags)) + '", ', end='')
    print(', '.join('accum_count[idx_%s]' % tag.name for tag in tags), end='')
    print(');')
    print('}')

    print('\n\n// HOOKS')

    for tag in tags:
        print('%s PRE_%s %s {' % (tag.return_type, tag.name, tag.signature))
        print('\tPRINT_FUNC_NAME;')
        print('\tpartial_count[idx_%s]++;' % tag.name)
        print('}\n')

        print('%s POST_%s %s {' % (tag.return_type, tag.name, tag.signature))
        print('\tPRINT_FUNC_NAME;')

        if tag.name == 'GOMP_parallel_end':
            print('\tprint_results_csv_partial();')

            print('int i;')
            print('\tfor (i = 0; i < NUM_FUNCTIONS; i++) {')
            print('\t\taccum_count[i] += partial_count[i];')
            print('\t\tpartial_count[i] = 0;')
            print('\t}')

            print('\tprint_results_csv_accum();')

        print('}\n')


    print('\n\n///GENERATED %d FUNCTIONS' % len(tags))
