# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jankovic/Documents/RG165-bethebachelor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jankovic/Documents/RG165-bethebachelor

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jankovic/Documents/RG165-bethebachelor/CMakeFiles /home/jankovic/Documents/RG165-bethebachelor/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jankovic/Documents/RG165-bethebachelor/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RG165_bethebachelor

# Build rule for target.
RG165_bethebachelor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RG165_bethebachelor
.PHONY : RG165_bethebachelor

# fast build rule for target.
RG165_bethebachelor/fast:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/build
.PHONY : RG165_bethebachelor/fast

src/callbackfuncs.o: src/callbackfuncs.cpp.o

.PHONY : src/callbackfuncs.o

# target to build an object file
src/callbackfuncs.cpp.o:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/callbackfuncs.cpp.o
.PHONY : src/callbackfuncs.cpp.o

src/callbackfuncs.i: src/callbackfuncs.cpp.i

.PHONY : src/callbackfuncs.i

# target to preprocess a source file
src/callbackfuncs.cpp.i:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/callbackfuncs.cpp.i
.PHONY : src/callbackfuncs.cpp.i

src/callbackfuncs.s: src/callbackfuncs.cpp.s

.PHONY : src/callbackfuncs.s

# target to generate assembly for a file
src/callbackfuncs.cpp.s:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/callbackfuncs.cpp.s
.PHONY : src/callbackfuncs.cpp.s

src/camera.o: src/camera.cpp.o

.PHONY : src/camera.o

# target to build an object file
src/camera.cpp.o:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/camera.cpp.o
.PHONY : src/camera.cpp.o

src/camera.i: src/camera.cpp.i

.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s

.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/figure.o: src/figure.cpp.o

.PHONY : src/figure.o

# target to build an object file
src/figure.cpp.o:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/figure.cpp.o
.PHONY : src/figure.cpp.o

src/figure.i: src/figure.cpp.i

.PHONY : src/figure.i

# target to preprocess a source file
src/figure.cpp.i:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/figure.cpp.i
.PHONY : src/figure.cpp.i

src/figure.s: src/figure.cpp.s

.PHONY : src/figure.s

# target to generate assembly for a file
src/figure.cpp.s:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/figure.cpp.s
.PHONY : src/figure.cpp.s

src/light.o: src/light.cpp.o

.PHONY : src/light.o

# target to build an object file
src/light.cpp.o:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/light.cpp.o
.PHONY : src/light.cpp.o

src/light.i: src/light.cpp.i

.PHONY : src/light.i

# target to preprocess a source file
src/light.cpp.i:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/light.cpp.i
.PHONY : src/light.cpp.i

src/light.s: src/light.cpp.s

.PHONY : src/light.s

# target to generate assembly for a file
src/light.cpp.s:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/light.cpp.s
.PHONY : src/light.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/RG165_bethebachelor.dir/build.make CMakeFiles/RG165_bethebachelor.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... RG165_bethebachelor"
	@echo "... edit_cache"
	@echo "... src/callbackfuncs.o"
	@echo "... src/callbackfuncs.i"
	@echo "... src/callbackfuncs.s"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/figure.o"
	@echo "... src/figure.i"
	@echo "... src/figure.s"
	@echo "... src/light.o"
	@echo "... src/light.i"
	@echo "... src/light.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

