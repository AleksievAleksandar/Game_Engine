# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build"

# Include any dependencies generated for this target.
include CMakeFiles/GameEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GameEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameEngine.dir/flags.make

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj: ../sdl_wrapper/SDL_Loader.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Loader.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Loader.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Loader.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Loader.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Loader.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Loader.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Loader.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj: ../sdl_wrapper/SDL_Helpers.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Helpers.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Helpers.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Helpers.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Helpers.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Helpers.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\SDL_Helpers.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\SDL_Helpers.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj: ../sdl_wrapper/Image_Handler.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\Image_Handler.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\Image_Handler.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Image_Handler.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Image_Handler.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\Image_Handler.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Image_Handler.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\Image_Handler.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj: ../sdl_wrapper/Input_Events.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\Input_Events.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\Input_Events.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Input_Events.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Input_Events.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\Input_Events.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Input_Events.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\Input_Events.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj: ../sdl_wrapper/Renderer.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\Renderer.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\Renderer.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Renderer.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Renderer.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\Renderer.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Renderer.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\Renderer.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj: ../sdl_wrapper/Window.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\Window.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\Window.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Window.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Window.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\Window.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\Window.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\Window.cpp.s

CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj: ../sdl_wrapper/config/ImageCfg.cpp
CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj -MF CMakeFiles\GameEngine.dir\sdl_wrapper\config\ImageCfg.cpp.obj.d -o CMakeFiles\GameEngine.dir\sdl_wrapper\config\ImageCfg.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\config\ImageCfg.cpp"

CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\config\ImageCfg.cpp" > CMakeFiles\GameEngine.dir\sdl_wrapper\config\ImageCfg.cpp.i

CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\sdl_wrapper\config\ImageCfg.cpp" -o CMakeFiles\GameEngine.dir\sdl_wrapper\config\ImageCfg.cpp.s

CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj: ../utils/drawing/Point.cpp
CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj -MF CMakeFiles\GameEngine.dir\utils\drawing\Point.cpp.obj.d -o CMakeFiles\GameEngine.dir\utils\drawing\Point.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Point.cpp"

CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Point.cpp" > CMakeFiles\GameEngine.dir\utils\drawing\Point.cpp.i

CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Point.cpp" -o CMakeFiles\GameEngine.dir\utils\drawing\Point.cpp.s

CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj: ../utils/drawing/Rectangle.cpp
CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj -MF CMakeFiles\GameEngine.dir\utils\drawing\Rectangle.cpp.obj.d -o CMakeFiles\GameEngine.dir\utils\drawing\Rectangle.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Rectangle.cpp"

CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Rectangle.cpp" > CMakeFiles\GameEngine.dir\utils\drawing\Rectangle.cpp.i

CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\drawing\Rectangle.cpp" -o CMakeFiles\GameEngine.dir\utils\drawing\Rectangle.cpp.s

CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj: ../utils/thread/ThreadUtils.cpp
CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj -MF CMakeFiles\GameEngine.dir\utils\thread\ThreadUtils.cpp.obj.d -o CMakeFiles\GameEngine.dir\utils\thread\ThreadUtils.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\thread\ThreadUtils.cpp"

CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\thread\ThreadUtils.cpp" > CMakeFiles\GameEngine.dir\utils\thread\ThreadUtils.cpp.i

CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\thread\ThreadUtils.cpp" -o CMakeFiles\GameEngine.dir\utils\thread\ThreadUtils.cpp.s

CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj: ../utils/time_measurement/Time.cpp
CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj -MF CMakeFiles\GameEngine.dir\utils\time_measurement\Time.cpp.obj.d -o CMakeFiles\GameEngine.dir\utils\time_measurement\Time.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\time_measurement\Time.cpp"

CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\time_measurement\Time.cpp" > CMakeFiles\GameEngine.dir\utils\time_measurement\Time.cpp.i

CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\utils\time_measurement\Time.cpp" -o CMakeFiles\GameEngine.dir\utils\time_measurement\Time.cpp.s

CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj: ../engine/Engine.cpp
CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj -MF CMakeFiles\GameEngine.dir\engine\Engine.cpp.obj.d -o CMakeFiles\GameEngine.dir\engine\Engine.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\engine\Engine.cpp"

CMakeFiles/GameEngine.dir/engine/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/engine/Engine.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\engine\Engine.cpp" > CMakeFiles\GameEngine.dir\engine\Engine.cpp.i

CMakeFiles/GameEngine.dir/engine/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/engine/Engine.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\engine\Engine.cpp" -o CMakeFiles\GameEngine.dir\engine\Engine.cpp.s

CMakeFiles/GameEngine.dir/main.cpp.obj: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/main.cpp.obj: CMakeFiles/GameEngine.dir/includes_CXX.rsp
CMakeFiles/GameEngine.dir/main.cpp.obj: ../main.cpp
CMakeFiles/GameEngine.dir/main.cpp.obj: CMakeFiles/GameEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/GameEngine.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameEngine.dir/main.cpp.obj -MF CMakeFiles\GameEngine.dir\main.cpp.obj.d -o CMakeFiles\GameEngine.dir\main.cpp.obj -c "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\main.cpp"

CMakeFiles/GameEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\main.cpp" > CMakeFiles\GameEngine.dir\main.cpp.i

CMakeFiles/GameEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\main.cpp" -o CMakeFiles\GameEngine.dir\main.cpp.s

# Object files for target GameEngine
GameEngine_OBJECTS = \
"CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj" \
"CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj" \
"CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj" \
"CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj" \
"CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj" \
"CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj" \
"CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj" \
"CMakeFiles/GameEngine.dir/main.cpp.obj"

# External object files for target GameEngine
GameEngine_EXTERNAL_OBJECTS =

GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Loader.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/SDL_Helpers.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/Image_Handler.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/Input_Events.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/Renderer.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/Window.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/sdl_wrapper/config/ImageCfg.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/utils/drawing/Point.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/utils/drawing/Rectangle.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/utils/thread/ThreadUtils.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/utils/time_measurement/Time.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/engine/Engine.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/main.cpp.obj
GameEngine.exe: CMakeFiles/GameEngine.dir/build.make
GameEngine.exe: C:/mingw_dev_libs/lib/libSDL2main.a
GameEngine.exe: C:/mingw_dev_libs/lib/libSDL2.dll.a
GameEngine.exe: C:/mingw_dev_libs/lib/libSDL2_image.dll.a
GameEngine.exe: C:/mingw_dev_libs/lib/libSDL2_ttf.dll.a
GameEngine.exe: C:/mingw_dev_libs/lib/libSDL2_mixer.dll.a
GameEngine.exe: CMakeFiles/GameEngine.dir/linklibs.rsp
GameEngine.exe: CMakeFiles/GameEngine.dir/objects1.rsp
GameEngine.exe: CMakeFiles/GameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable GameEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GameEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameEngine.dir/build: GameEngine.exe
.PHONY : CMakeFiles/GameEngine.dir/build

CMakeFiles/GameEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GameEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GameEngine.dir/clean

CMakeFiles/GameEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine" "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine" "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build" "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build" "D:\Aleksandar\Projects\Cpp Projects\SoftUni\Cpp_Master_Class\My_First_Game\Game_Engine\Game_Engine\build\CMakeFiles\GameEngine.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GameEngine.dir/depend

