# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/F_HMD.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/F_HMD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/F_HMD.dir/flags.make

CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.obj: CMakeFiles/F_HMD.dir/flags.make
CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.obj: ../FILE_OPS_DEL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\F_HMD.dir\FILE_OPS_DEL.c.obj   -c C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\FILE_OPS_DEL.c

CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\FILE_OPS_DEL.c > CMakeFiles\F_HMD.dir\FILE_OPS_DEL.c.i

CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\FILE_OPS_DEL.c -o CMakeFiles\F_HMD.dir\FILE_OPS_DEL.c.s

# Object files for target F_HMD
F_HMD_OBJECTS = \
"CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.obj"

# External object files for target F_HMD
F_HMD_EXTERNAL_OBJECTS =

libF_HMD.dll: CMakeFiles/F_HMD.dir/FILE_OPS_DEL.c.obj
libF_HMD.dll: CMakeFiles/F_HMD.dir/build.make
libF_HMD.dll: CMakeFiles/F_HMD.dir/linklibs.rsp
libF_HMD.dll: CMakeFiles/F_HMD.dir/objects1.rsp
libF_HMD.dll: CMakeFiles/F_HMD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libF_HMD.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\F_HMD.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/F_HMD.dir/build: libF_HMD.dll

.PHONY : CMakeFiles/F_HMD.dir/build

CMakeFiles/F_HMD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\F_HMD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/F_HMD.dir/clean

CMakeFiles/F_HMD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug C:\Users\Ghost\Desktop\Programming\C\sys\F.HMD\cmake-build-debug\CMakeFiles\F_HMD.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/F_HMD.dir/depend

