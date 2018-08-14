CC=gcc-4.8
CXX=g++-4.8
#LIB_HOOKOMP_PATH=$(PWD)/..
LIB_HOOKOMP_PATH=/home/${USER}/openmp.info/src/simple-omp-hook/

all: clean main

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ${LIB_HOOKOMP_PATH}/libhookomp.so .
	
	# ${CXX} -L ${LIB_HOOKOMP_PATH} parallel-region-with-tasks.c -o parallel-region-with-tasks.exe -lhookomp -fopenmp -lgomp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c hook-test.c -lhookomp -fopenmp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} hook-test.o prepostfunctions.o -o hook-test.exe -lhookomp -fopenmp
	
	@echo "*****Use: LD_PRELOAD=./libhookomp.so ./hook-test.exe"
	
clean:
	rm -rf *.o *.so *.exe

