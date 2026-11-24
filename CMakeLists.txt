# CMake configuration for the astro-cargo-hauler project
cmake_minimum_required(VERSION 3.14) 
project("astro-cargo-hauler" LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard to C++ s20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the MSVC debug information format to EditAndContinue for Debug and RelWithDebInfo configurations
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

include(FetchContent)

# Fetch the FTXUI library from GitHub
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG        v5.0.0 # Use the latest stable release
)

# Disable building examples and tests for FTXUI to quickly compile.
set(FTXUI_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(FTXUI_BUILD_TESTS OFF CACHE INTERNAL "")

# Make the FTXUI available to the project.
FetchContent_MakeAvailable(ftxui)

# Create the executable target
add_executable(astro-cargo-hauler 
    "astro-cargo-hauler.cpp" 
    "astro-cargo-hauler.h"
  "player.cpp" "player.h"
  "main_menu.cpp" "main_menu.h" "inventory.cpp" "inventory.h" "item.h" "game_ui.h" "game_ui.cpp")

# Target the FTXUI libraries to the executable
target_link_libraries(astro-cargo-hauler PRIVATE 
    ftxui::screen 
    ftxui::dom 
    ftxui::component
)

# Check if the target platform is Windows
if(WIN32)
    target_compile_definitions(astro-cargo-hauler PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()
