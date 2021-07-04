# Files-Generator

Theses scripts generate the files to `hook` in OpenMP.

## Operation
1. ~~Extract the functions name from the `libgomp_g.h` using `ctags`~~
2. Download the `.c` [files](https://github.com/DanielVenturini/openmp.info/blob/master/src/files-generator/worker.py#L38L40) from **libgomp** [repository](https://github.com/DanielVenturini/openmp.info/blob/master/src/files-generator/worker.py#L36) and saved in `src/`
3. Extract the names and the prototypes of all functions in `.c` files
4. Filter the `GOMP_` and `GOACC_` functions
5. Using `pycparser` generate the functions calls string
 - These strings will be used in `hookomp.c` file to calls the original function
 - Using `pycparser` because some prototypes contains complex parameters names, such as:
```
void GOMP_taskloop (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE  ep)
```
6. Save the file name, function name, prototype and function calls in array, that will be used to generate the code
7. After, each file to `hook` will be generate from the `tags` that was generate and saved in `output/`

## Model
The path `model` contain the scripts that will be inserted at top and bottom of each generated files. For example, when the file `src/prepostdef.h` will be generated, all content from the file `model/pre_ppd.c` is written in the top of `src/prepostdef.h`. Then, the functions are generated and written. By the last, the content of file `model/pos_ppd.c` is written at bottom of `src/prepostdef.h`. This is the step to generate one file.

The files `model/pre_[abreviation].c` and `model/pos_[abreviation].c` is used to write some code directly in `C`, because is hard to write this code directly in the `python` files. It's better to write `printf("%d", var);` in `C` files instead `fp.write("printf(\"%d\", var);\n")` directly in `python` files. For this, all static code is written in `model/[pre|pos]_[abreviation].c` files.

## Install ctags and pycparser
 - `sh ctags.sh`
 - `pip3 install pycparser`

## Use
To generate all files, just run
```bash
python3 worker.py
```
then all files will be generated. To avoid download the `.c` files each time, when the file is downloaded, the `sha1` of it is calculated and save into `src/sha1json`. The next time when the command is runner, the files will be downloaded if the `sha1` of them is diff from the `src/sha1json`.