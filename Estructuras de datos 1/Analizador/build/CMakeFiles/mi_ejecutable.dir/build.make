# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiza/Analizador

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiza/Analizador/build

# Include any dependencies generated for this target.
include CMakeFiles/mi_ejecutable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mi_ejecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mi_ejecutable.dir/flags.make

CMakeFiles/mi_ejecutable.dir/dictionary.c.o: CMakeFiles/mi_ejecutable.dir/flags.make
CMakeFiles/mi_ejecutable.dir/dictionary.c.o: ../dictionary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mi_ejecutable.dir/dictionary.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mi_ejecutable.dir/dictionary.c.o   -c /home/tiza/Analizador/dictionary.c

CMakeFiles/mi_ejecutable.dir/dictionary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mi_ejecutable.dir/dictionary.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiza/Analizador/dictionary.c > CMakeFiles/mi_ejecutable.dir/dictionary.c.i

CMakeFiles/mi_ejecutable.dir/dictionary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mi_ejecutable.dir/dictionary.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiza/Analizador/dictionary.c -o CMakeFiles/mi_ejecutable.dir/dictionary.c.s

CMakeFiles/mi_ejecutable.dir/hashtable.c.o: CMakeFiles/mi_ejecutable.dir/flags.make
CMakeFiles/mi_ejecutable.dir/hashtable.c.o: ../hashtable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mi_ejecutable.dir/hashtable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mi_ejecutable.dir/hashtable.c.o   -c /home/tiza/Analizador/hashtable.c

CMakeFiles/mi_ejecutable.dir/hashtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mi_ejecutable.dir/hashtable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiza/Analizador/hashtable.c > CMakeFiles/mi_ejecutable.dir/hashtable.c.i

CMakeFiles/mi_ejecutable.dir/hashtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mi_ejecutable.dir/hashtable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiza/Analizador/hashtable.c -o CMakeFiles/mi_ejecutable.dir/hashtable.c.s

CMakeFiles/mi_ejecutable.dir/word.c.o: CMakeFiles/mi_ejecutable.dir/flags.make
CMakeFiles/mi_ejecutable.dir/word.c.o: ../word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mi_ejecutable.dir/word.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mi_ejecutable.dir/word.c.o   -c /home/tiza/Analizador/word.c

CMakeFiles/mi_ejecutable.dir/word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mi_ejecutable.dir/word.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiza/Analizador/word.c > CMakeFiles/mi_ejecutable.dir/word.c.i

CMakeFiles/mi_ejecutable.dir/word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mi_ejecutable.dir/word.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiza/Analizador/word.c -o CMakeFiles/mi_ejecutable.dir/word.c.s

CMakeFiles/mi_ejecutable.dir/trie.c.o: CMakeFiles/mi_ejecutable.dir/flags.make
CMakeFiles/mi_ejecutable.dir/trie.c.o: ../trie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mi_ejecutable.dir/trie.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mi_ejecutable.dir/trie.c.o   -c /home/tiza/Analizador/trie.c

CMakeFiles/mi_ejecutable.dir/trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mi_ejecutable.dir/trie.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiza/Analizador/trie.c > CMakeFiles/mi_ejecutable.dir/trie.c.i

CMakeFiles/mi_ejecutable.dir/trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mi_ejecutable.dir/trie.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiza/Analizador/trie.c -o CMakeFiles/mi_ejecutable.dir/trie.c.s

CMakeFiles/mi_ejecutable.dir/main.c.o: CMakeFiles/mi_ejecutable.dir/flags.make
CMakeFiles/mi_ejecutable.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mi_ejecutable.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mi_ejecutable.dir/main.c.o   -c /home/tiza/Analizador/main.c

CMakeFiles/mi_ejecutable.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mi_ejecutable.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiza/Analizador/main.c > CMakeFiles/mi_ejecutable.dir/main.c.i

CMakeFiles/mi_ejecutable.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mi_ejecutable.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiza/Analizador/main.c -o CMakeFiles/mi_ejecutable.dir/main.c.s

# Object files for target mi_ejecutable
mi_ejecutable_OBJECTS = \
"CMakeFiles/mi_ejecutable.dir/dictionary.c.o" \
"CMakeFiles/mi_ejecutable.dir/hashtable.c.o" \
"CMakeFiles/mi_ejecutable.dir/word.c.o" \
"CMakeFiles/mi_ejecutable.dir/trie.c.o" \
"CMakeFiles/mi_ejecutable.dir/main.c.o"

# External object files for target mi_ejecutable
mi_ejecutable_EXTERNAL_OBJECTS =

mi_ejecutable: CMakeFiles/mi_ejecutable.dir/dictionary.c.o
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/hashtable.c.o
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/word.c.o
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/trie.c.o
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/main.c.o
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/build.make
mi_ejecutable: CMakeFiles/mi_ejecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tiza/Analizador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable mi_ejecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mi_ejecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mi_ejecutable.dir/build: mi_ejecutable

.PHONY : CMakeFiles/mi_ejecutable.dir/build

CMakeFiles/mi_ejecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mi_ejecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mi_ejecutable.dir/clean

CMakeFiles/mi_ejecutable.dir/depend:
	cd /home/tiza/Analizador/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiza/Analizador /home/tiza/Analizador /home/tiza/Analizador/build /home/tiza/Analizador/build /home/tiza/Analizador/build/CMakeFiles/mi_ejecutable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mi_ejecutable.dir/depend
