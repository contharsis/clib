# legend

CC - compiler collection
CFLAGS - compilation flags
FD - source code folders, sources and libraries
VPATH - folders which Makefile will search for prerequisites
CDIR - folders which compiler will search for headers and source code
SRCDIR - folders which we add an .o file for compilation for each .c file
VFLAGS - valgrind options
RS - run state
RSF - run state file containing last run state
OUT - output binary file
RC - run command to execute after compilation
FS - which .o files to use for compilation

# how to run

inside main project folder, create 3 folders
src, lib, build, put Makefile in build, put source code in src and libraries in lib
go in build, make fs, now put output in FS variable inside Makefile or run make FS=<output>

currently 3 run states are available, nl for normal (default), dbg which compiles without
optimizations for debugging and mem which uses valgrind to check memory
to add a run state, simply run with the run state inside RS variable, like make RS=dbg,mem

# what can be configured?
everything is automatic except the defined folders for searching which are by default
in the variable FD with value "../src ../lib", which is then used to set these variables
for other Makefile variables, when changing run states everything is automatically recompiled
then again only the changed source files

source code and headers searched folders can be set as absolute or relative paths in FD variable
