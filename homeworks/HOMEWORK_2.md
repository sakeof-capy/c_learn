# Homework 2.

## Intro to Makefiles.

### Overview
`Make` is a build automation tool primarily used to compile and build projects.
In this homework you will learn to use `Make` for convenient automatic project building.
You will no longer need to specify all of the .c files to compile your program.
Instead of:
```bash
gcc 3_arrays/bin/main.c 3_arrays/src/array_utilities.c 3_arrays/src/error_code_processing.c && ./a.exe
```
you will have 
```bash
make <smth>
```

### Task
1. Add Makefile z your could use to run `3_arrays` project.
2. Add a global Makefile z you could use to run any subproject of `c_learn` project by specifying the option identifying the subproject. Example:
```bash
make 3_arrays # execute 3_arrays project
make 2_spusk_andreevskii # execute 2_spusk_andreevskii project
```