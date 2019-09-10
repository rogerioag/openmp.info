import os

def gen_libhookomp(dir_output)
	os.getstatusoutput('make -f libhookomp.make DIR_OUTPUT={}'.format(dir_output))