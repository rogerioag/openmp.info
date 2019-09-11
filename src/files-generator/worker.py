import os
import parse_tag
import subprocess           as sp
import downloader           as dw
import gen_hookomp_h        as ghh
import gen_hookomp_c        as ghc
import gen_prepostdef       as gppd
import gen_libhookomp       as glho
import gen_prepostfunctions as gppf

# verify if exists the paths
# if it doesn't exists, create it
def verify_paths(paths):
    for path in paths:
        if not os.path.isdir(path):
            os.makedirs(path)

# using ctags, generate the tags from file
def generate_tags(file_ctags, file):
    print('generate tags...', end='', flush=True)
    sp.getstatusoutput('ctags -f {0} --c++-kinds=+p+l --fields=SK --sort=no {1}'.format(file_ctags, file))
    print('OK')

"""
    VARIABLES
"""
# file to extract the tags
file       = 'libgomp_g.h'
# file to save ctags - current it isn't used
file_ctags = 'tags.txt'
# dir to save the downloadeds files
dir_src    = 'src/'
# dir to save the generated files
dir_output = 'output/'
# url to repository
repo_url   = 'https://raw.githubusercontent.com/gcc-mirror/gcc/master/libgomp/'
# files to download from repository and save in dir_src
files      = ['atomic.c', 'barrier.c', 'critical.c', 'loop.c',
              'loop_ull.c', 'ordered.c', 'parallel.c', 'sections.c',
              'single.c', 'task.c', 'target.c', 'taskloop.c', 'oacc-parallel.c']

"""
    EXECUTE
"""
verify_paths([dir_src, dir_output])

generate_tags(file_ctags, file)
dw.download(dir_src, repo_url, files)

tags = parse_tag.parse(dir_src, dir_output, files)
print('\n')

# generate the nexts files
ghh.gen_hookomp_h(tags, dir_output + 'hookomp.h')
ghc.gen_hookomp_c(tags, dir_output + 'hookomp.c')
gppd.gen_prepostdef(tags, dir_output + 'prepostdef.h')
gppf.gen_prepostfunctions(tags, dir_output + 'prepostfunctions.c')
glho.gen_libhookomp(dir_output)