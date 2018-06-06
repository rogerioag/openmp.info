import os
import urllib.request
import subprocess
import shlex
from collections import namedtuple
import pycparser

parser = pycparser.CParser()
Function = namedtuple('Function', 'file name return_type signature call')


def parse():
    functions = []

    arq = open('tags.txt', 'r')
    lines = arq.readlines()
    for line in lines:
        fields = line.split('\t')
        func_name = fields[0]

        if len(fields) > 4 and 'prototype' in fields and func_name not in [x for x in functions]:
            functions.append(func_name)

    arq.close()

    repository_url = 'https://raw.githubusercontent.com/gcc-mirror/gcc/master/libgomp/'
    files = ['atomic.c', 'barrier.c', 'critical.c', 'loop.c', 'loop_ull.c', 'ordered.c',
             'parallel.c', 'sections.c', 'single.c', 'task.c', 'target.c', 'taskloop.c',
             'oacc-parallel.c']

    os.system('rm -rf src/')
    os.system('mkdir -p src')
    os.chdir('src')

    all_tags = []

    for f in files:
        urllib.request.urlretrieve(repository_url + f, f)

        # remove linhas contendo 'ialias'
        # 'ialias' estava atrapalhando o ctags de encontrar algumas funções
        os.system('sed -i \'/ialias/d\' {}'.format(f))

        proc = subprocess.Popen(shlex.split('ctags -f - --fields=St {}'.format(f)),
                                stdout=subprocess.PIPE,
                                stdin=subprocess.PIPE,
                                bufsize=1,
                                universal_newlines=True)

        tags = proc.stdout.readlines()
        for tag in tags:
            fields = tag.split('\t')
            func_name = fields[0]

            if (func_name.startswith('GOMP_') or func_name.startswith('GOACC_')) and func_name not in [x.name for x in all_tags] and len(fields) > 4:
                return_type = fields[3].replace('typeref:typename:', '')
                signature = fields[4].replace(
                    'signature:', '').replace('\n', '')
                s = return_type + ' ' + func_name + ' ' + signature + '{}'

                # Substitui alguns tipos
                # Restaurar quando for gerar o código
                s = s.replace('bool', '_Bool')
                s = s.replace('gomp_ull', 'unsigned long long')
                s = s.replace('size_t', 'unsigned int')
                s = s.replace('TYPE', 'long')
                ast = parser.parse(s)
                param_list = ast.children()[0][1].children()[0][1].children()[
                    0][1].children()[0][1]

                args_str = ''

                for c in param_list.children():
                    if not isinstance(c[1], pycparser.c_ast.EllipsisParam):
                        if c[1].name is not None:
                            args_str += c[1].name + ', '
                args_str = '(' + args_str[:-2] + ')'

                all_tags.append(Function(f, func_name, return_type, signature, args_str))
    return all_tags
