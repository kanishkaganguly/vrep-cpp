# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/kanishka/Downloads/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kanishka/Downloads/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kanishka/Documents/Projects/task_planner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanishka/Documents/Projects/task_planner/build

# Include any dependencies generated for this target.
include CMakeFiles/task_planner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task_planner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task_planner.dir/flags.make

CMakeFiles/task_planner.dir/external/extApi.c.o: CMakeFiles/task_planner.dir/flags.make
CMakeFiles/task_planner.dir/external/extApi.c.o: ../external/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task_planner.dir/external/extApi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task_planner.dir/external/extApi.c.o   -c /home/kanishka/Documents/Projects/task_planner/external/extApi.c

CMakeFiles/task_planner.dir/external/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task_planner.dir/external/extApi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kanishka/Documents/Projects/task_planner/external/extApi.c > CMakeFiles/task_planner.dir/external/extApi.c.i

CMakeFiles/task_planner.dir/external/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task_planner.dir/external/extApi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kanishka/Documents/Projects/task_planner/external/extApi.c -o CMakeFiles/task_planner.dir/external/extApi.c.s

CMakeFiles/task_planner.dir/external/extApi.c.o.requires:

.PHONY : CMakeFiles/task_planner.dir/external/extApi.c.o.requires

CMakeFiles/task_planner.dir/external/extApi.c.o.provides: CMakeFiles/task_planner.dir/external/extApi.c.o.requires
	$(MAKE) -f CMakeFiles/task_planner.dir/build.make CMakeFiles/task_planner.dir/external/extApi.c.o.provides.build
.PHONY : CMakeFiles/task_planner.dir/external/extApi.c.o.provides

CMakeFiles/task_planner.dir/external/extApi.c.o.provides.build: CMakeFiles/task_planner.dir/external/extApi.c.o


CMakeFiles/task_planner.dir/external/extApiPlatform.c.o: CMakeFiles/task_planner.dir/flags.make
CMakeFiles/task_planner.dir/external/extApiPlatform.c.o: ../external/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/task_planner.dir/external/extApiPlatform.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task_planner.dir/external/extApiPlatform.c.o   -c /home/kanishka/Documents/Projects/task_planner/external/extApiPlatform.c

CMakeFiles/task_planner.dir/external/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task_planner.dir/external/extApiPlatform.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kanishka/Documents/Projects/task_planner/external/extApiPlatform.c > CMakeFiles/task_planner.dir/external/extApiPlatform.c.i

CMakeFiles/task_planner.dir/external/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task_planner.dir/external/extApiPlatform.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kanishka/Documents/Projects/task_planner/external/extApiPlatform.c -o CMakeFiles/task_planner.dir/external/extApiPlatform.c.s

CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.requires:

.PHONY : CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.requires

CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.provides: CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.requires
	$(MAKE) -f CMakeFiles/task_planner.dir/build.make CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.provides.build
.PHONY : CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.provides

CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.provides.build: CMakeFiles/task_planner.dir/external/extApiPlatform.c.o


CMakeFiles/task_planner.dir/src/blah.cpp.o: CMakeFiles/task_planner.dir/flags.make
CMakeFiles/task_planner.dir/src/blah.cpp.o: ../src/blah.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task_planner.dir/src/blah.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_planner.dir/src/blah.cpp.o -c /home/kanishka/Documents/Projects/task_planner/src/blah.cpp

CMakeFiles/task_planner.dir/src/blah.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_planner.dir/src/blah.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishka/Documents/Projects/task_planner/src/blah.cpp > CMakeFiles/task_planner.dir/src/blah.cpp.i

CMakeFiles/task_planner.dir/src/blah.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_planner.dir/src/blah.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishka/Documents/Projects/task_planner/src/blah.cpp -o CMakeFiles/task_planner.dir/src/blah.cpp.s

CMakeFiles/task_planner.dir/src/blah.cpp.o.requires:

.PHONY : CMakeFiles/task_planner.dir/src/blah.cpp.o.requires

CMakeFiles/task_planner.dir/src/blah.cpp.o.provides: CMakeFiles/task_planner.dir/src/blah.cpp.o.requires
	$(MAKE) -f CMakeFiles/task_planner.dir/build.make CMakeFiles/task_planner.dir/src/blah.cpp.o.provides.build
.PHONY : CMakeFiles/task_planner.dir/src/blah.cpp.o.provides

CMakeFiles/task_planner.dir/src/blah.cpp.o.provides.build: CMakeFiles/task_planner.dir/src/blah.cpp.o


CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o: CMakeFiles/task_planner.dir/flags.make
CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o: ../src/vrep_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o -c /home/kanishka/Documents/Projects/task_planner/src/vrep_utils.cpp

CMakeFiles/task_planner.dir/src/vrep_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_planner.dir/src/vrep_utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishka/Documents/Projects/task_planner/src/vrep_utils.cpp > CMakeFiles/task_planner.dir/src/vrep_utils.cpp.i

CMakeFiles/task_planner.dir/src/vrep_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_planner.dir/src/vrep_utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishka/Documents/Projects/task_planner/src/vrep_utils.cpp -o CMakeFiles/task_planner.dir/src/vrep_utils.cpp.s

CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.requires:

.PHONY : CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.requires

CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.provides: CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/task_planner.dir/build.make CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.provides.build
.PHONY : CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.provides

CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.provides.build: CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o


CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o: CMakeFiles/task_planner.dir/flags.make
CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o: ../src/vrep_kinect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o -c /home/kanishka/Documents/Projects/task_planner/src/vrep_kinect.cpp

CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishka/Documents/Projects/task_planner/src/vrep_kinect.cpp > CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.i

CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishka/Documents/Projects/task_planner/src/vrep_kinect.cpp -o CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.s

CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.requires:

.PHONY : CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.requires

CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.provides: CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.requires
	$(MAKE) -f CMakeFiles/task_planner.dir/build.make CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.provides.build
.PHONY : CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.provides

CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.provides.build: CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o


# Object files for target task_planner
task_planner_OBJECTS = \
"CMakeFiles/task_planner.dir/external/extApi.c.o" \
"CMakeFiles/task_planner.dir/external/extApiPlatform.c.o" \
"CMakeFiles/task_planner.dir/src/blah.cpp.o" \
"CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o" \
"CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o"

# External object files for target task_planner
task_planner_EXTERNAL_OBJECTS =

task_planner: CMakeFiles/task_planner.dir/external/extApi.c.o
task_planner: CMakeFiles/task_planner.dir/external/extApiPlatform.c.o
task_planner: CMakeFiles/task_planner.dir/src/blah.cpp.o
task_planner: CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o
task_planner: CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o
task_planner: CMakeFiles/task_planner.dir/build.make
task_planner: /usr/local/lib/libcilantro.so
task_planner: /usr/local/lib/libpangolin.so
task_planner: /usr/lib/x86_64-linux-gnu/libGLU.so
task_planner: /usr/lib/x86_64-linux-gnu/libGL.so
task_planner: /usr/lib/x86_64-linux-gnu/libGLEW.so
task_planner: /usr/lib/x86_64-linux-gnu/libSM.so
task_planner: /usr/lib/x86_64-linux-gnu/libICE.so
task_planner: /usr/lib/x86_64-linux-gnu/libX11.so
task_planner: /usr/lib/x86_64-linux-gnu/libXext.so
task_planner: /usr/lib/x86_64-linux-gnu/libpython3.5m.so
task_planner: /usr/lib/x86_64-linux-gnu/libavcodec.so
task_planner: /usr/lib/x86_64-linux-gnu/libavformat.so
task_planner: /usr/lib/x86_64-linux-gnu/libavutil.so
task_planner: /usr/lib/x86_64-linux-gnu/libswscale.so
task_planner: /usr/lib/libOpenNI.so
task_planner: /usr/lib/libOpenNI2.so
task_planner: /usr/lib/x86_64-linux-gnu/libpng.so
task_planner: /usr/lib/x86_64-linux-gnu/libz.so
task_planner: /usr/lib/x86_64-linux-gnu/libjpeg.so
task_planner: /usr/lib/x86_64-linux-gnu/libtiff.so
task_planner: /usr/lib/x86_64-linux-gnu/libIlmImf.so
task_planner: CMakeFiles/task_planner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanishka/Documents/Projects/task_planner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable task_planner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_planner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task_planner.dir/build: task_planner

.PHONY : CMakeFiles/task_planner.dir/build

CMakeFiles/task_planner.dir/requires: CMakeFiles/task_planner.dir/external/extApi.c.o.requires
CMakeFiles/task_planner.dir/requires: CMakeFiles/task_planner.dir/external/extApiPlatform.c.o.requires
CMakeFiles/task_planner.dir/requires: CMakeFiles/task_planner.dir/src/blah.cpp.o.requires
CMakeFiles/task_planner.dir/requires: CMakeFiles/task_planner.dir/src/vrep_utils.cpp.o.requires
CMakeFiles/task_planner.dir/requires: CMakeFiles/task_planner.dir/src/vrep_kinect.cpp.o.requires

.PHONY : CMakeFiles/task_planner.dir/requires

CMakeFiles/task_planner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task_planner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task_planner.dir/clean

CMakeFiles/task_planner.dir/depend:
	cd /home/kanishka/Documents/Projects/task_planner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanishka/Documents/Projects/task_planner /home/kanishka/Documents/Projects/task_planner /home/kanishka/Documents/Projects/task_planner/build /home/kanishka/Documents/Projects/task_planner/build /home/kanishka/Documents/Projects/task_planner/build/CMakeFiles/task_planner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task_planner.dir/depend
