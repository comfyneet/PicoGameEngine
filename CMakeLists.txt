cmake_minimum_required(VERSION 3.10.3 FATAL_ERROR)
cmake_policy(VERSION 3.10.3)

project(PicoGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared library")
set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD TRUE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# https://cmake.org/Wiki/CMake_FAQ#Can_I_do_.22make_uninstall.22_with_CMake.3F
configure_file(
   "${CMAKE_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
   "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
   IMMEDIATE @ONLY)
add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_uninstall.cmake)

if (NOT DEFINED CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Debug")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
   set(PGE_BUILD_TYPE "Debug")
else()
   set(PGE_BUILD_TYPE "Release")
endif()

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
   set(PGE_ARCHITECTURE "x64")
else()
   set(PGE_ARCHITECTURE "x86")
endif()

if (WIN32)
   set(PGE_OS "Windows")
endif()

if (PGE_OS STREQUAL "Windows")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
else()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic")
endif()

add_subdirectory("src")
add_subdirectory("examples")
