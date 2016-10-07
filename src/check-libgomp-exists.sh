#!/bin/sh
# listar as tags.
# svn ls svn://gcc.gnu.org/svn/gcc/tags

# get releases:
#  svn co svn://gcc.gnu.org/svn/gcc/tags/gcc_6_1_0_release gcc-6.1.0

# git clone git://gcc.gnu.org/git/gcc.git

for gcc_tag in `svn ls svn://gcc.gnu.org/svn/gcc/tags | grep "^gcc_"`; do
	gcc_version=`echo $gcc_tag | cut -d/ -f 1`
	echo "Checking: ${gcc_version}"

	svn info svn://gcc.gnu.org/svn/gcc/tags/${gcc_version}/libgomp/libgomp.map &> ${gcc_version}-libgomp.info
	if [ $? -eq 0 ]
	then
		mkdir -p ${gcc_version}/libgomp && svn export svn://gcc.gnu.org/svn/gcc/tags/${gcc_version}/libgomp/libgomp.map ${gcc_version}/libgomp/libgomp.map
	else
		echo "Não existe no ${gcc_version}."
	fi	
done



