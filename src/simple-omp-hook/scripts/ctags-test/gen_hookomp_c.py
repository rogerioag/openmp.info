import parse_tag

tags = parse_tag.parse()
visited_files = []

for tag in tags:
    if tag.file not in visited_files:
        print('/* ------------------------------------------------------------- */')
        print('/* %s' % tag.file)
        print('/* ------------------------------------------------------------- */')
        visited_files.append(tag.file)

    print('%s %s %s {' % (tag.return_type, tag.name, tag.signature))
    print('\tPRINT_FUNC_NAME;')
    print('\tGET_RUNTIME_FUNCTION(lib_%s, "%s");' % (tag.name, tag.name))
    print('\tTRACE("[hookomp]: Thread [%%lu] is executing %s.\\n", (unsigned long int)pthread_self());' % tag.name)
    print('\tPRE_%s%s;' % (tag.name, tag.call))
    print('\tlib_%s%s;' % (tag.name, tag.call))
    print('\tPOST_%s%s;' % (tag.name, tag.call))
    print('}\n')

print('\n\n///GENERATED %d FUNCTIONS' % len(tags))