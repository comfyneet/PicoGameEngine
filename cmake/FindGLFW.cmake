# https://cmake.org/Wiki/CMake:How_To_Find_Libraries#Writing_find_modules
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h
   /usr/include
   /usr/local/include
   ${CMAKE_SOURCE_DIR}/extlibs/GLFW/include
)

find_library(GLFW_LIBRARY glfw3
   /usr/lib
   /usr/local/lib
   ${CMAKE_SOURCE_DIR}/extlibs/GLFW/lib/${ARCHITECTURE})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLFW DEFAULT_MSG
                                  GLFW_INCLUDE_DIR GLFW_LIBRARY)

mark_as_advanced(GLFW_INCLUDE_DIR GLFW_LIBRARY)

set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
set(GLFW_LIBRARIES ${GLFW_LIBRARY})
