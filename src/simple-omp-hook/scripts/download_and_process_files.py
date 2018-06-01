import urllib.request
import os
from pycparser import parse_file

os.system('rm -rf src/')
os.system('mkdir -p src')

repository_url = 'https://raw.githubusercontent.com/gcc-mirror/gcc/master/libgomp/'
files = ['barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
         'parallel.c', 'sections.c', 'single.c']

#files = ['task.c', 'target.c']
# excluded files with errors: task.c target.c

for f in files:
    urllib.request.urlretrieve(repository_url + f, 'src/' + f)

# remove includes
os.system('sed -i  \'/#include/d\' src/*')

os.chdir('src')

for f in files:
    os.system('gcc -E ' + f + ' > ' + f + '.out')

# remove some parts of code
os.system('sed  -e \'s/bool/_Bool/g\' -i *')
os.system('sed  -e \'s/size_t/unsigned int/g\' -i *')
os.system('sed  -e \'s/hashval_t/unsigned int/g\' -i *')
os.system('sed  -e \'s/pthread_once_t/unsigned int/g\' -i *')
os.system('sed  \'/#/d\' -i *')
os.system('sed  \'/static gomp_mutex_t/d\' -i *')
os.system("sed  '/{$/ {:r;/\\n}/!{N;br}; s/\\n.*\\n/\\n/}' -i *")
os.system('sed  \'/static void __attribute__((constructor))/d\' -i *')
os.system('sed  \'/ialias/d\' -i *')
os.system('sed  \'/typedef struct gomp_task_depend_entry/d\' -i *')

for f in files:
    parse_file(f + '.out')
