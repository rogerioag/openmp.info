CC=gcc-4.8	# it's required because the latest gcc doesn't print
CXX=g++-4.8

LIB_HOOKOMP_PATH=/home/${USER}/git/openmp.info/src/simple-omp-hook/

all: clean cp main run

# copy the generated files
cp:
	cp ../../output/libhookomp.so .
	cp ../../output/prepostfunctions.c .
	cp ../../static/debug.h .

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c parallel-region-with-tasks.c -lhookomp -fopenmp
	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -fdump-tree-ompexp parallel-region-with-tasks.c -fopenmp

	${CC} -I . -L . parallel-region-with-tasks.o prepostfunctions.o -o parallel-region-with-tasks.exe -lhookomp -fopenmp

run:
	LD_LIBRARY_PATH=. LD_PRELOAD=./libhookomp.so ./parallel-region-with-tasks.exe 10
	
clean:
	rm -rf *.o *.so *.exe *.ompexp *.out prepostfunctions.c debug.h *.json