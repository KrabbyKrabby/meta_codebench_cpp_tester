# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build

# Include any dependencies generated for this target.
include CMakeFiles/base_code_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/base_code_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/base_code_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base_code_tests.dir/flags.make

CMakeFiles/base_code_tests.dir/codegen:
.PHONY : CMakeFiles/base_code_tests.dir/codegen

CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o: CMakeFiles/base_code_tests.dir/flags.make
CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o: /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/tests/test_model.cpp
CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o: CMakeFiles/base_code_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o -MF CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o.d -o CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o -c /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/tests/test_model.cpp

CMakeFiles/base_code_tests.dir/tests/test_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/base_code_tests.dir/tests/test_model.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/tests/test_model.cpp > CMakeFiles/base_code_tests.dir/tests/test_model.cpp.i

CMakeFiles/base_code_tests.dir/tests/test_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/base_code_tests.dir/tests/test_model.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/tests/test_model.cpp -o CMakeFiles/base_code_tests.dir/tests/test_model.cpp.s

# Object files for target base_code_tests
base_code_tests_OBJECTS = \
"CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o"

# External object files for target base_code_tests
base_code_tests_EXTERNAL_OBJECTS =

base_code_tests: CMakeFiles/base_code_tests.dir/tests/test_model.cpp.o
base_code_tests: CMakeFiles/base_code_tests.dir/build.make
base_code_tests: lib/libgtest_main.a
base_code_tests: lib/libgtest.a
base_code_tests: CMakeFiles/base_code_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable base_code_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base_code_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base_code_tests.dir/build: base_code_tests
.PHONY : CMakeFiles/base_code_tests.dir/build

CMakeFiles/base_code_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base_code_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base_code_tests.dir/clean

CMakeFiles/base_code_tests.dir/depend:
	cd /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206 /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206 /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build /Users/ittehad/Documents/Coding/Python/Turing/Tester_cpp_copy/tasks/621206/build/CMakeFiles/base_code_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/base_code_tests.dir/depend

