# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Soft\Clion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Soft\Clion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Programming\Clion projects\Lab1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Programming\Clion projects\Lab1\cmake-build-debug"

# Include any dependencies generated for this target.
include Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/flags.make

Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/flags.make
Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/includes_CXX.rsp
Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: ../Google_tests/googletest-master/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Programming\Clion projects\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && C:\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.obj -c "D:\Programming\Clion projects\Lab1\Google_tests\googletest-master\googletest\src\gtest_main.cc"

Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Programming\Clion projects\Lab1\Google_tests\googletest-master\googletest\src\gtest_main.cc" > CMakeFiles\gtest_main.dir\src\gtest_main.cc.i

Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Programming\Clion projects\Lab1\Google_tests\googletest-master\googletest\src\gtest_main.cc" -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_maind.a: Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
lib/libgtest_maind.a: Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_maind.a: Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Programming\Clion projects\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libgtest_maind.a"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean_target.cmake
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_maind.a

.PHONY : Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/build

Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean.cmake
.PHONY : Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/clean

Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Programming\Clion projects\Lab1" "D:\Programming\Clion projects\Lab1\Google_tests\googletest-master\googletest" "D:\Programming\Clion projects\Lab1\cmake-build-debug" "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest" "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\googletest-master\googletest\CMakeFiles\gtest_main.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : Google_tests/googletest-master/googletest/CMakeFiles/gtest_main.dir/depend
