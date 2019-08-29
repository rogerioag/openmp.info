import requests

path = '/home/venturini/git/openmp.info/src/check-libgomp/python/'

# from the line 'svn://gcc.gnu.org/svn/gcc/tags/gcc_4_0_0_release/libgomp/libgomp.map\n'
# remove the 'svn:' and replace by 'https:' to do a request and remove the \n
def format_line(line):
    return line.replace('svn:', 'https:').strip()

# return true if request response is OK
def request(url):
    return requests.head(url).status_code == 200

# check the existents mirror of repository release
def check_existence():
    file_name_input    = 'arquivo_versoes.txt'
    file_name_output   = 'arquivo_versoes{}.txt'
    file_fail_output   = open(path + file_name_output.format('_fail'), 'w')
    file_sucess_output = open(path + file_name_output.format('_sucess'), 'w')

    for line in open(path + file_name_input).readlines():
        print(line)
        file_sucess_output.write(line) if request(format_line(line)) else file_fail_output.write(line)

    file_fail_output.close()
    file_sucess_output.close()

#check_existence()