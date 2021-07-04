import subprocess as sp

def gen_libhookomp(dir_output):
	print('generate {}libhookomp.so...'.format(dir_output), end='', flush=True)
	sp.getstatusoutput('make -f libhookomp.make DIR_OUTPUT={}'.format(dir_output))
	print('OK')