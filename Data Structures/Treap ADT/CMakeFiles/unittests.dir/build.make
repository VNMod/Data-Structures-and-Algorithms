# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT"

# Include any dependencies generated for this target.
include CMakeFiles/unittests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unittests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unittests.dir/flags.make

CMakeFiles/unittests.dir/test_catch.cpp.o: CMakeFiles/unittests.dir/flags.make
CMakeFiles/unittests.dir/test_catch.cpp.o: test_catch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unittests.dir/test_catch.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittests.dir/test_catch.cpp.o -c "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/test_catch.cpp"

CMakeFiles/unittests.dir/test_catch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittests.dir/test_catch.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/test_catch.cpp" > CMakeFiles/unittests.dir/test_catch.cpp.i

CMakeFiles/unittests.dir/test_catch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittests.dir/test_catch.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/test_catch.cpp" -o CMakeFiles/unittests.dir/test_catch.cpp.s

CMakeFiles/unittests.dir/unittests.cpp.o: CMakeFiles/unittests.dir/flags.make
CMakeFiles/unittests.dir/unittests.cpp.o: unittests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unittests.dir/unittests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittests.dir/unittests.cpp.o -c "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/unittests.cpp"

CMakeFiles/unittests.dir/unittests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittests.dir/unittests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/unittests.cpp" > CMakeFiles/unittests.dir/unittests.cpp.i

CMakeFiles/unittests.dir/unittests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittests.dir/unittests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/unittests.cpp" -o CMakeFiles/unittests.dir/unittests.cpp.s

# Object files for target unittests
unittests_OBJECTS = \
"CMakeFiles/unittests.dir/test_catch.cpp.o" \
"CMakeFiles/unittests.dir/unittests.cpp.o"

# External object files for target unittests
unittests_EXTERNAL_OBJECTS =

unittests: CMakeFiles/unittests.dir/test_catch.cpp.o
unittests: CMakeFiles/unittests.dir/unittests.cpp.o
unittests: CMakeFiles/unittests.dir/build.make
unittests: CMakeFiles/unittests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable unittests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unittests.dir/build: unittests

.PHONY : CMakeFiles/unittests.dir/build

CMakeFiles/unittests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unittests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unittests.dir/clean

CMakeFiles/unittests.dir/depend:
	cd "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT" "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT" "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT" "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT" "/Users/varunmodak/Desktop/GitHub Projects/Data-Structures-and-Algorithms/Data Structures/Treap ADT/CMakeFiles/unittests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/unittests.dir/depend

