# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-3.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin

# Include any dependencies generated for this target.
include CMakeFiles/Trackpad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Trackpad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trackpad.dir/flags.make

CMakeFiles/Trackpad.dir/src/Trackpad.mm.o: CMakeFiles/Trackpad.dir/flags.make
CMakeFiles/Trackpad.dir/src/Trackpad.mm.o: ../src/Trackpad.mm
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Trackpad.dir/src/Trackpad.mm.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Trackpad.dir/src/Trackpad.mm.o -c /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/Trackpad.mm

CMakeFiles/Trackpad.dir/src/Trackpad.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trackpad.dir/src/Trackpad.mm.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/Trackpad.mm > CMakeFiles/Trackpad.dir/src/Trackpad.mm.i

CMakeFiles/Trackpad.dir/src/Trackpad.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trackpad.dir/src/Trackpad.mm.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/src/Trackpad.mm -o CMakeFiles/Trackpad.dir/src/Trackpad.mm.s

CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.requires:
.PHONY : CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.requires

CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.provides: CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.requires
	$(MAKE) -f CMakeFiles/Trackpad.dir/build.make CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.provides.build
.PHONY : CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.provides

CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.provides.build: CMakeFiles/Trackpad.dir/src/Trackpad.mm.o
.PHONY : CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.provides.build

# Object files for target Trackpad
Trackpad_OBJECTS = \
"CMakeFiles/Trackpad.dir/src/Trackpad.mm.o"

# External object files for target Trackpad
Trackpad_EXTERNAL_OBJECTS =

Trackpad.a: CMakeFiles/Trackpad.dir/src/Trackpad.mm.o
Trackpad.a: CMakeFiles/Trackpad.dir/build.make
Trackpad.a: CMakeFiles/Trackpad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library Trackpad.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Trackpad.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Trackpad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trackpad.dir/build: Trackpad.a
.PHONY : CMakeFiles/Trackpad.dir/build

CMakeFiles/Trackpad.dir/requires: CMakeFiles/Trackpad.dir/src/Trackpad.mm.o.requires
.PHONY : CMakeFiles/Trackpad.dir/requires

CMakeFiles/Trackpad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Trackpad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Trackpad.dir/clean

CMakeFiles/Trackpad.dir/depend:
	cd /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin /Users/diederickhuijbers/c++/__PLAYGROUND__/multitouch/bin/CMakeFiles/Trackpad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Trackpad.dir/depend

