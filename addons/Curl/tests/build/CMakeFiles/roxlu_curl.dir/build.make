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
CMAKE_SOURCE_DIR = /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/roxlu_curl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roxlu_curl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roxlu_curl.dir/flags.make

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o: CMakeFiles/roxlu_curl.dir/flags.make
CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o: ../../src/kurl/Kurl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o -c /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp > CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.i

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp -o CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.s

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.requires:
.PHONY : CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.requires

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.provides: CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.requires
	$(MAKE) -f CMakeFiles/roxlu_curl.dir/build.make CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.provides.build
.PHONY : CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.provides

CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.provides.build: CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o
.PHONY : CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.provides.build

# Object files for target roxlu_curl
roxlu_curl_OBJECTS = \
"CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o"

# External object files for target roxlu_curl
roxlu_curl_EXTERNAL_OBJECTS =

libroxlu_curl.a: CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o
libroxlu_curl.a: CMakeFiles/roxlu_curl.dir/build.make
libroxlu_curl.a: CMakeFiles/roxlu_curl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libroxlu_curl.a"
	$(CMAKE_COMMAND) -P CMakeFiles/roxlu_curl.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roxlu_curl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roxlu_curl.dir/build: libroxlu_curl.a
.PHONY : CMakeFiles/roxlu_curl.dir/build

CMakeFiles/roxlu_curl.dir/requires: CMakeFiles/roxlu_curl.dir/src/kurl/Kurl.cpp.o.requires
.PHONY : CMakeFiles/roxlu_curl.dir/requires

CMakeFiles/roxlu_curl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roxlu_curl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roxlu_curl.dir/clean

CMakeFiles/roxlu_curl.dir/depend:
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/CMakeFiles/roxlu_curl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roxlu_curl.dir/depend

