CC=gcc-4.8
CXX=g++
#LIB_HOOKOMP_PATH=$(PWD)/..

LIB_HOOKOMP_PATH=/home/${USER}/openmp.info/src/simple-omp-hook/

all: clean main

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ../libhookomp.so .
	
	# ${CXX} -L ${LIB_HOOKOMP_PATH} parallel-region-with-one-loop.c -o parallel-region-with-one-loop.exe -lhookomp -fopenmp -lgomp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c parallel-region-with-one-loop.c -lhookomp -fopenmp
	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -fdump-tree-ompexp parallel-region-with-one-loop.c -fopenmp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} parallel-region-with-one-loop.o prepostfunctions.o -o parallel-region-with-one-loop.exe -lhookomp -fopenmp
	
	@echo "*****Use: LD_LIBRARY_PATH=. LD_PRELOAD=./libhookomp.so ./parallel-region-with-one-loop.exe"
	
clean:
	rm -rf *.o *.so *.exe

