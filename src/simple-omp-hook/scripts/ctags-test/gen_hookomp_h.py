import parse_tag

tags = parse_tag.parse()
visited_files = []

for tag in tags:
    if tag.file not in visited_files:
        print('\n/* ------------------------------------------------------------- */')
        print('/* %s' % tag.file)
        print('/* ------------------------------------------------------------- */')
        visited_files.append(tag.file)

    print('%s (*lib_%s) %s;' % (tag.return_type, tag.name, tag.signature))


print('\n\n// --------------------  END OF PART 1\n\n')

visited_files.clear()

for tag in tags:
    if tag.file not in visited_files:
        print('\n/* ------------------------------------------------------------- */')
        print('/* %s' % tag.file)
        print('/* ------------------------------------------------------------- */')
        visited_files.append(tag.file)

    print('%s %s %s;' % (tag.return_type, tag.name, tag.signature))

print('\n\n///GENERATED %d FUNCTIONS' % len(tags))