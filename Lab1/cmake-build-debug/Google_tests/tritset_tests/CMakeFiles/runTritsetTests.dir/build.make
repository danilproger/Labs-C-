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
include Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/depend.make

# Include the progress variables for this target.
include Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/progress.make

# Include the compile flags for this target's objects.
include Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/flags.make

Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.obj: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/flags.make
Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.obj: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/includes_CXX.rsp
Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.obj: ../Google_tests/tritset_tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Programming\Clion projects\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.obj"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" && C:\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runTritsetTests.dir\tests.cpp.obj -c "D:\Programming\Clion projects\Lab1\Google_tests\tritset_tests\tests.cpp"

Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTritsetTests.dir/tests.cpp.i"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Programming\Clion projects\Lab1\Google_tests\tritset_tests\tests.cpp" > CMakeFiles\runTritsetTests.dir\tests.cpp.i

Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTritsetTests.dir/tests.cpp.s"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" && C:\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Programming\Clion projects\Lab1\Google_tests\tritset_tests\tests.cpp" -o CMakeFiles\runTritsetTests.dir\tests.cpp.s

# Object files for target runTritsetTests
runTritsetTests_OBJECTS = \
"CMakeFiles/runTritsetTests.dir/tests.cpp.obj"

# External object files for target runTritsetTests
runTritsetTests_EXTERNAL_OBJECTS =

Google_tests/tritset_tests/runTritsetTests.exe: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/tests.cpp.obj
Google_tests/tritset_tests/runTritsetTests.exe: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/build.make
Google_tests/tritset_tests/runTritsetTests.exe: lib/libgtestd.a
Google_tests/tritset_tests/runTritsetTests.exe: lib/libgtest_maind.a
Google_tests/tritset_tests/runTritsetTests.exe: lib/libgtestd.a
Google_tests/tritset_tests/runTritsetTests.exe: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/linklibs.rsp
Google_tests/tritset_tests/runTritsetTests.exe: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/objects1.rsp
Google_tests/tritset_tests/runTritsetTests.exe: Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Programming\Clion projects\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTritsetTests.exe"
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\runTritsetTests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/build: Google_tests/tritset_tests/runTritsetTests.exe

.PHONY : Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/build

Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/clean:
	cd /d "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" && $(CMAKE_COMMAND) -P CMakeFiles\runTritsetTests.dir\cmake_clean.cmake
.PHONY : Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/clean

Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Programming\Clion projects\Lab1" "D:\Programming\Clion projects\Lab1\Google_tests\tritset_tests" "D:\Programming\Clion projects\Lab1\cmake-build-debug" "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests" "D:\Programming\Clion projects\Lab1\cmake-build-debug\Google_tests\tritset_tests\CMakeFiles\runTritsetTests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : Google_tests/tritset_tests/CMakeFiles/runTritsetTests.dir/depend

