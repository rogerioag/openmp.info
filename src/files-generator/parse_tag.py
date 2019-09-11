import os
import subprocess
import shlex
from collections import namedtuple
import pycparser

parser = pycparser.CParser()
Function = namedtuple('Function', 'file name return_type signature call')

# Obs.: necessário desinstalar o ctags caso estiver instalado no sistema
# Compilar o ctags que está na pasta
#  ./autogen.sh
#  ./configure
#  make
#  sudo make install

def parse(dir_src, dir_output, files):
    functions = []

    """
    arq = open('tags.txt', 'r')
    lines = arq.readlines()
    for line in lines:
        fields = line.split('\t')
        func_name = fields[0]

        if len(fields) > 4 and 'prototype' in fields and func_name not in functions:
            functions.append(func_name)

    arq.close()
    """

    current_dir = os.path.abspath('./')
    os.chdir(dir_src)

    all_tags = []

    for f in files:
        print('process file {}...'.format(f), end='', flush=True)

        # remove linhas contendo 'ialias'
        # 'ialias' estava atrapalhando o ctags de encontrar algumas funções
        # o comando daqui já foi feito antes de calcular o sha1
        proc = subprocess.Popen(shlex.split('ctags -f - --fields=St {}'.format(f)),
                                stdout=subprocess.PIPE,
                                stdin=subprocess.PIPE,
                                bufsize=1,
                                universal_newlines=True)

        tags = proc.stdout.readlines()
        for tag in tags:

            fields = tag.split('\t')
            func_name = fields[0]
            
            if (func_name.startswith('GOMP_') or func_name.startswith('GOACC_')) and func_name not in [x.name for x in all_tags] and len(fields) > 4 :
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
                # add typedef to c++11 definition
                s = 'typedef int uintptr_t;' + s
                ast = parser.parse(s)
                # remove the ast node for c++11 definition
                ast = ast.children()[1]
                param_list = ast[1].children()[0][1].children()[0][1].children()[0][1]

                args_str = ''

                for c in param_list.children():
                    if not isinstance(c[1], pycparser.c_ast.EllipsisParam):
                        if c[1].name is not None:
                            args_str += c[1].name + ', '
                args_str = '(' + args_str[:-2] + ')'

                all_tags.append(
                    Function(f, func_name, return_type, signature, args_str))

        print('OK.')

    os.chdir(current_dir)
    return all_tags