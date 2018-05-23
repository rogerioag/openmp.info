all: default clang-libgomp clang-libomp

default:
	clang teste-omp.c -fopenmp -o teste-omp-clang-default.exe
	clang teste-omp.c -fopenmp -S -o teste-omp-clang-default.s

clang-libgomp:
	clang -V teste-omp.c -fopenmp=libgomp -o teste-omp-clang-libgomp.exe
	clang teste-omp.c -fopenmp=libgomp -S -o teste-omp-clang-libgomp.s

clang-libomp:
	clang teste-omp.c -fopenmp=libomp -o teste-omp-clang-libomp.exe
	clang teste-omp.c -fopenmp=libomp -S -o teste-omp-clang-libomp.s

end:
	@echo "Fim da compilação."

clean:
	rm *.exe *.s


