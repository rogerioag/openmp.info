"""
Download all files from the github and save in src
Then, calcule the sha1 to avoid download a twice
"""

import os
import json
import urllib.request
from hashlib import sha1

def save_sha1(files):
    sha1json = {}

    # get sha1 for each file
    for file in files:
        sha1json[file] = sha1(open(file).read().encode()).hexdigest()

    # save json
    json.dump(sha1json, open('sha1json', 'w'), indent=4, sort_keys=True)

# just open, if exists, the sha1json and verify the file sha1
### this function can be otmized, because from each file the sha1 file is opened
def verify_sha1(file):
    try:
        sha1json = json.load(open('sha1json'))
        sha1file = sha1(open(file).read().encode()).hexdigest()
        return True if sha1json[file] == sha1file else False
    except FileNotFoundError:
        return False

def download(dir_src, repo_url, files):
    # change the paths to work
    current_dir = os.path.abspath('./')
    os.chdir(dir_src)

    for file in files:
        print('download file {}...'.format(file), end='', flush=True)

        if verify_sha1(file):
            print('CACHE')
            continue

        urllib.request.urlretrieve(repo_url + file, file)
        # must be done after get sha1
        # remove lines with 'ialias', because it cause confuse in ctags
        os.system('sed -i \'/ialias/d\' {}'.format(file))
        print('DOWNLOADED')

    save_sha1(files)
    # come back to path
    os.chdir(current_dir)
    print()