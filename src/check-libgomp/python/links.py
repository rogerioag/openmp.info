import os
import re
import requests
import svn.remote

home     = os.getenv('HOME')
path     = home + '/git/openmp.info/src/check-libgomp/python/'
tags_url = 'svn://gcc.gnu.org/svn/gcc/tags/'

# files to save the urls of releases files
releases_file_name_input  = 'releases_gcc'
releases_file_name_output = 'releases_gcc{}'

# save releases in file
def save_releases(gcc_releases):
    file = open(path + releases_file_name_input, 'w')
    for release in gcc_releases:
        file.write(tags_url + release + 'libgomp/libgomp.map\n')

    file.close()

# the rule to be a gcc release
# currently, the rule is the release name starts with 'gcc_'
def is_gcc_release(file):
    return re.search('^gcc_', file)

# get all gcc releases/tags from gcc.gnu.org
def get_gcc_releases():
    gcc_releases = []
    tags = svn.remote.RemoteClient(tags_url).list()
    for file in tags:
        # save only the gcc releases files
        if is_gcc_release(file):
            gcc_releases.append(file)

    save_releases(gcc_releases)

# from the line 'svn://gcc.gnu.org/svn/gcc/tags/gcc_4_0_0_release/libgomp/libgomp.map\n'
# remove the 'svn:' and replace by 'https:' to do a request and remove the \n
def format_line(line):
    return line.replace('svn:', 'https:').strip()

# return true if request response is OK
def request(url):
    return requests.head(url).status_code == 200

# check the existents mirror of repository release
def check_existence():
    file_fail_output   = open(path + releases_file_name_output.format('_fail'), 'w')
    file_sucess_output = open(path + releases_file_name_output.format('_sucess'), 'w')

    for line in open(path + releases_file_name_input).readlines():
        print(line, end='')
        file_sucess_output.write(line) if request(format_line(line)) else file_fail_output.write(line)

    file_fail_output.close()
    file_sucess_output.close()

if __name__ == '__main__':
    get_gcc_releases()
    check_existence()