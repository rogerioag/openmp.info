import urllib.request
import os
import re
from pycparser import parse_file

os.system('rm -rf src/')
os.system('mkdir -p src')

repository_url = 'https://raw.githubusercontent.com/gcc-mirror/gcc/master/libgomp/'
#files = ['atomic.c', 'barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
#         'parallel.c', 'sections.c', 'single.c', 'task.c', 'target.c']

files = ['target.c']
# excluded files with errors: task.c target.c


def comment_remover(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "  # note: a space and not an empty string
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)


for f in files:
    urllib.request.urlretrieve(repository_url + f, 'src/' + f)

    f_handle = open('src/' + f, 'r')
    text = comment_remover(f_handle.read())

    lines = text.split('\n')
    for i in range(len(lines)):
        if 'GOMP_' in lines[i]:
            s = lines[i]
            while '{' not in lines[i]:
                i += 1
                s += lines[i]
            s += '}'
            print(s)
    f_handle.close()

# remove includes
# os.system(
#    'sed -i'' -e  \'s|/\\*|\\n&|g;s|*/|&\\n|g\' src/*  | sed \'/\\/\\*/,/*\\//d\'')
# os.system('sed -i  \'/#/d\' src/*')
#os.system("sed  -i '/{$/ {:r;/\\n}/!{N;br}; s/\\n.*\\n/\\n/}' src/*")
#os.system('sed -i \'/extern/d\' src/*')
#os.system('sed -i \'/__attribute__/d\' src/*')
#os.system('sed -i \'/ialias/d\' src/*')

# os.chdir('src')

# for f in files:
#     os.system('gcc -E ' + f + ' > ' + f + '.out')

# for f in files:
#     arq = open(f, 'r')

#     lines = arq.readlines()
#     for i in range(len(lines)):
#         if 'GOMP_' in lines[i]:
#             s = lines[i]
#             while '{' not in lines[i]:
#                 i += 1
#                 s += lines[i]
#             s += '}'
#             print(s)
#         # print(lines[i])

#     arq.close()
# # remove some parts of code
# os.system('sed  -e \'s/bool/_Bool/g\' -i *')
# os.system('sed  -e \'s/size_t/unsigned int/g\' -i *')
# os.system('sed  -e \'s/hashval_t/unsigned int/g\' -i *')
# os.system('sed  -e \'s/pthread_once_t/unsigned int/g\' -i *')
# os.system('sed  \'/#/d\' -i *')
# os.system('sed  \'/static gomp_mutex_t/d\' -i *')
# os.system("sed  '/{$/ {:r;/\\n}/!{N;br}; s/\\n.*\\n/\\n/}' -i *")
# os.system('sed  \'/static void __attribute__((constructor))/d\' -i *')
# os.system('sed  \'/ialias/d\' -i *')
# os.system('sed  \'/typedef struct gomp_task_depend_entry/d\' -i *')

# for f in files:
#     parse_file(f + '.out')
