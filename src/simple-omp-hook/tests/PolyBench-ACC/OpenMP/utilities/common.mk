INCPATHS = -I$(UTIL_DIR)

BENCHMARK = $(shell basename `pwd`)
EXE = $(BENCHMARK)_acc
SRC = $(BENCHMARK).c
HEADERS = $(BENCHMARK).h

LIB_HOOKOMP_PATH=/home/${USER}/openmp.info/src/simple-omp-hook/

SRC += $(UTIL_DIR)/polybench.c

DEPS        := Makefile.dep
DEP_FLAG    := -MM

.PHONY: all exe clean veryclean

all : exe

exe : $(EXE)

$(EXE) : $(SRC)

	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ${LIB_HOOKOMP_PATH}/libhookomp.so .

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	$(CC) $(CFLAGS) $(INCPATHS) -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} $^ prepostfunctions.o -o $@ -lm -lhookomp -fopenmp

clean :
	-rm -vf __hmpp* -vf $(EXE) *~ 

veryclean : clean
	-rm -vf $(DEPS)

$(DEPS): $(SRC) $(HEADERS)
	$(CC) $(INCPATHS) $(DEP_FLAG) $(SRC) > $(DEPS)

-include $(DEPS)