# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/HW2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW2.dir/flags.make

CMakeFiles/HW2.dir/main.cpp.o: CMakeFiles/HW2.dir/flags.make
CMakeFiles/HW2.dir/main.cpp.o: /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW2.dir/main.cpp.o -c /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/main.cpp

CMakeFiles/HW2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/main.cpp > CMakeFiles/HW2.dir/main.cpp.i

CMakeFiles/HW2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/main.cpp -o CMakeFiles/HW2.dir/main.cpp.s

CMakeFiles/HW2.dir/my_quick_sorts.cpp.o: CMakeFiles/HW2.dir/flags.make
CMakeFiles/HW2.dir/my_quick_sorts.cpp.o: /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/my_quick_sorts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HW2.dir/my_quick_sorts.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW2.dir/my_quick_sorts.cpp.o -c /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/my_quick_sorts.cpp

CMakeFiles/HW2.dir/my_quick_sorts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW2.dir/my_quick_sorts.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/my_quick_sorts.cpp > CMakeFiles/HW2.dir/my_quick_sorts.cpp.i

CMakeFiles/HW2.dir/my_quick_sorts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW2.dir/my_quick_sorts.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/my_quick_sorts.cpp -o CMakeFiles/HW2.dir/my_quick_sorts.cpp.s

# Object files for target HW2
HW2_OBJECTS = \
"CMakeFiles/HW2.dir/main.cpp.o" \
"CMakeFiles/HW2.dir/my_quick_sorts.cpp.o"

# External object files for target HW2
HW2_EXTERNAL_OBJECTS =

HW2: CMakeFiles/HW2.dir/main.cpp.o
HW2: CMakeFiles/HW2.dir/my_quick_sorts.cpp.o
HW2: CMakeFiles/HW2.dir/build.make
HW2: CMakeFiles/HW2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HW2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW2.dir/build: HW2
.PHONY : CMakeFiles/HW2.dir/build

CMakeFiles/HW2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW2.dir/clean

CMakeFiles/HW2.dir/depend:
	cd /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2 /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2 /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug /Users/seungwookim/Desktop/ksw/Sogang/4학기/알고리즘설계와분석/과제/HW2/cmake-build-debug/CMakeFiles/HW2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW2.dir/depend

