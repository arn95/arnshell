# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aballiu/ClionProjects/arnshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aballiu/ClionProjects/arnshell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arnshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arnshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arnshell.dir/flags.make

CMakeFiles/arnshell.dir/driver.c.o: CMakeFiles/arnshell.dir/flags.make
CMakeFiles/arnshell.dir/driver.c.o: ../driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arnshell.dir/driver.c.o"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arnshell.dir/driver.c.o   -c /Users/aballiu/ClionProjects/arnshell/driver.c

CMakeFiles/arnshell.dir/driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arnshell.dir/driver.c.i"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aballiu/ClionProjects/arnshell/driver.c > CMakeFiles/arnshell.dir/driver.c.i

CMakeFiles/arnshell.dir/driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arnshell.dir/driver.c.s"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aballiu/ClionProjects/arnshell/driver.c -o CMakeFiles/arnshell.dir/driver.c.s

CMakeFiles/arnshell.dir/driver.c.o.requires:

.PHONY : CMakeFiles/arnshell.dir/driver.c.o.requires

CMakeFiles/arnshell.dir/driver.c.o.provides: CMakeFiles/arnshell.dir/driver.c.o.requires
	$(MAKE) -f CMakeFiles/arnshell.dir/build.make CMakeFiles/arnshell.dir/driver.c.o.provides.build
.PHONY : CMakeFiles/arnshell.dir/driver.c.o.provides

CMakeFiles/arnshell.dir/driver.c.o.provides.build: CMakeFiles/arnshell.dir/driver.c.o


CMakeFiles/arnshell.dir/helpers.c.o: CMakeFiles/arnshell.dir/flags.make
CMakeFiles/arnshell.dir/helpers.c.o: ../helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/arnshell.dir/helpers.c.o"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arnshell.dir/helpers.c.o   -c /Users/aballiu/ClionProjects/arnshell/helpers.c

CMakeFiles/arnshell.dir/helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arnshell.dir/helpers.c.i"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aballiu/ClionProjects/arnshell/helpers.c > CMakeFiles/arnshell.dir/helpers.c.i

CMakeFiles/arnshell.dir/helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arnshell.dir/helpers.c.s"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aballiu/ClionProjects/arnshell/helpers.c -o CMakeFiles/arnshell.dir/helpers.c.s

CMakeFiles/arnshell.dir/helpers.c.o.requires:

.PHONY : CMakeFiles/arnshell.dir/helpers.c.o.requires

CMakeFiles/arnshell.dir/helpers.c.o.provides: CMakeFiles/arnshell.dir/helpers.c.o.requires
	$(MAKE) -f CMakeFiles/arnshell.dir/build.make CMakeFiles/arnshell.dir/helpers.c.o.provides.build
.PHONY : CMakeFiles/arnshell.dir/helpers.c.o.provides

CMakeFiles/arnshell.dir/helpers.c.o.provides.build: CMakeFiles/arnshell.dir/helpers.c.o


CMakeFiles/arnshell.dir/tokenizer.c.o: CMakeFiles/arnshell.dir/flags.make
CMakeFiles/arnshell.dir/tokenizer.c.o: ../tokenizer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/arnshell.dir/tokenizer.c.o"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arnshell.dir/tokenizer.c.o   -c /Users/aballiu/ClionProjects/arnshell/tokenizer.c

CMakeFiles/arnshell.dir/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arnshell.dir/tokenizer.c.i"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aballiu/ClionProjects/arnshell/tokenizer.c > CMakeFiles/arnshell.dir/tokenizer.c.i

CMakeFiles/arnshell.dir/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arnshell.dir/tokenizer.c.s"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aballiu/ClionProjects/arnshell/tokenizer.c -o CMakeFiles/arnshell.dir/tokenizer.c.s

CMakeFiles/arnshell.dir/tokenizer.c.o.requires:

.PHONY : CMakeFiles/arnshell.dir/tokenizer.c.o.requires

CMakeFiles/arnshell.dir/tokenizer.c.o.provides: CMakeFiles/arnshell.dir/tokenizer.c.o.requires
	$(MAKE) -f CMakeFiles/arnshell.dir/build.make CMakeFiles/arnshell.dir/tokenizer.c.o.provides.build
.PHONY : CMakeFiles/arnshell.dir/tokenizer.c.o.provides

CMakeFiles/arnshell.dir/tokenizer.c.o.provides.build: CMakeFiles/arnshell.dir/tokenizer.c.o


CMakeFiles/arnshell.dir/string.c.o: CMakeFiles/arnshell.dir/flags.make
CMakeFiles/arnshell.dir/string.c.o: ../string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/arnshell.dir/string.c.o"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arnshell.dir/string.c.o   -c /Users/aballiu/ClionProjects/arnshell/string.c

CMakeFiles/arnshell.dir/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arnshell.dir/string.c.i"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/aballiu/ClionProjects/arnshell/string.c > CMakeFiles/arnshell.dir/string.c.i

CMakeFiles/arnshell.dir/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arnshell.dir/string.c.s"
	/Applications/Xcode-Beta-8.2.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/aballiu/ClionProjects/arnshell/string.c -o CMakeFiles/arnshell.dir/string.c.s

CMakeFiles/arnshell.dir/string.c.o.requires:

.PHONY : CMakeFiles/arnshell.dir/string.c.o.requires

CMakeFiles/arnshell.dir/string.c.o.provides: CMakeFiles/arnshell.dir/string.c.o.requires
	$(MAKE) -f CMakeFiles/arnshell.dir/build.make CMakeFiles/arnshell.dir/string.c.o.provides.build
.PHONY : CMakeFiles/arnshell.dir/string.c.o.provides

CMakeFiles/arnshell.dir/string.c.o.provides.build: CMakeFiles/arnshell.dir/string.c.o


# Object files for target arnshell
arnshell_OBJECTS = \
"CMakeFiles/arnshell.dir/driver.c.o" \
"CMakeFiles/arnshell.dir/helpers.c.o" \
"CMakeFiles/arnshell.dir/tokenizer.c.o" \
"CMakeFiles/arnshell.dir/string.c.o"

# External object files for target arnshell
arnshell_EXTERNAL_OBJECTS =

arnshell: CMakeFiles/arnshell.dir/driver.c.o
arnshell: CMakeFiles/arnshell.dir/helpers.c.o
arnshell: CMakeFiles/arnshell.dir/tokenizer.c.o
arnshell: CMakeFiles/arnshell.dir/string.c.o
arnshell: CMakeFiles/arnshell.dir/build.make
arnshell: CMakeFiles/arnshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable arnshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arnshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arnshell.dir/build: arnshell

.PHONY : CMakeFiles/arnshell.dir/build

CMakeFiles/arnshell.dir/requires: CMakeFiles/arnshell.dir/driver.c.o.requires
CMakeFiles/arnshell.dir/requires: CMakeFiles/arnshell.dir/helpers.c.o.requires
CMakeFiles/arnshell.dir/requires: CMakeFiles/arnshell.dir/tokenizer.c.o.requires
CMakeFiles/arnshell.dir/requires: CMakeFiles/arnshell.dir/string.c.o.requires

.PHONY : CMakeFiles/arnshell.dir/requires

CMakeFiles/arnshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arnshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arnshell.dir/clean

CMakeFiles/arnshell.dir/depend:
	cd /Users/aballiu/ClionProjects/arnshell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aballiu/ClionProjects/arnshell /Users/aballiu/ClionProjects/arnshell /Users/aballiu/ClionProjects/arnshell/cmake-build-debug /Users/aballiu/ClionProjects/arnshell/cmake-build-debug /Users/aballiu/ClionProjects/arnshell/cmake-build-debug/CMakeFiles/arnshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arnshell.dir/depend

