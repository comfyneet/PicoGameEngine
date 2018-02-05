cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)
cmake_policy(VERSION 3.9.2)

project(PicoGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
if (CMAKE_VERSION VERSION_LESS "3.10" AND MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
set(BUILD_SHARED_LIBS TRUE)
set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD TRUE)
set(INSTALL_DIR "${CMAKE_BINARY_DIR}/bin")

# https://cmake.org/Wiki/CMake_FAQ#Can_I_do_.22make_uninstall.22_with_CMake.3F
configure_file(
   "${CMAKE_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
   "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
   IMMEDIATE @ONLY)
add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_uninstall.cmake)

if (WIN32)
   include(CheckTypeSize)
   check_type_size(void* SIZEOF_VOID_PTR)
   if (${SIZEOF_VOID_PTR} EQUAL 4)
      set(ARCHITECTURE "x86")
   elseif(${SIZEOF_VOID_PTR} EQUAL 8)
      set(ARCHITECTURE "x64")
   endif()
   string(REPLACE "/W3" "" WINDOWS_FLAGS ${CMAKE_CXX_FLAGS})
   set(CMAKE_CXX_FLAGS "${WINDOWS_FLAGS} /W4 /WX")
else()
   set(CMAKE_INSTALL_RPATH ${INSTALL_DIR})
   set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory("src")
add_subdirectory("examples")
