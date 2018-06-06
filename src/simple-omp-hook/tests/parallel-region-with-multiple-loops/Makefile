CC=gcc
CXX=g++
#LIB_HOOKOMP_PATH=$(PWD)/..
LIB_HOOKOMP_PATH:~/Projects/openmp.info/src/simple-omp-hook/

all: clean main

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ../libhookomp.so .
	
	# ${CXX} -L ${LIB_HOOKOMP_PATH} parallel-region-with-multiple-loops.c -o parallel-region-with-multiple-loops.exe -lhookomp -fopenmp -lgomp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c parallel-region-with-multiple-loops.c -lhookomp -fopenmp
	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -fdump-tree-ompexp parallel-region-with-multiple-loops.c -fopenmp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} parallel-region-with-multiple-loops.o prepostfunctions.o -o parallel-region-with-multiple-loops.exe -lhookomp -fopenmp
	
	@echo "*****Use: LD_LIBRARY_PATH=. LD_PRELOAD=./libhookomp.so ./parallel-region-with-multiple-loops.exe"
	
clean:
	rm -rf *.o *.so *.exe

