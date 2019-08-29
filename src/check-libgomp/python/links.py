import os
import re
import requests
import svn.remote

home     = os.getenv('HOME')
path     = home + '/git/openmp.info/src/check-libgomp/python/'
tags_url = 'svn://gcc.gnu.org/svn/gcc/tags'

# get all gcc releases/tags from gcc.gnu.org
def get_gcc_releases():
    gcc_releases = []
    tags = svn.remote.RemoteClient(tags_url).list()
    for file in tags:
        # save only the gcc releases files
        if re.search('^gcc_', file):
            gcc_releases.append(file)

    return gcc_releases

# from the line 'svn://gcc.gnu.org/svn/gcc/tags/gcc_4_0_0_release/libgomp/libgomp.map\n'
# remove the 'svn:' and replace by 'https:' to do a request and remove the \n
def format_line(line):
    return line.replace('svn:', 'https:').strip()

# return true if request response is OK
def request(url):
    return requests.head(url).status_code == 200

# check the existents mirror of repository release
def check_existence():
    file_name_input    = 'versions_file'
    file_name_output   = 'versions_file{}'
    file_fail_output   = open(path + file_name_output.format('_fail'), 'w')
    file_sucess_output = open(path + file_name_output.format('_sucess'), 'w')

    for line in open(path + file_name_input).readlines():
        print(line)
        file_sucess_output.write(line) if request(format_line(line)) else file_fail_output.write(line)

    file_fail_output.close()
    file_sucess_output.close()

get_gcc_releases()
#check_existence()