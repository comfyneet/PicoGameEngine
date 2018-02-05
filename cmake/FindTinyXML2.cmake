# https://cmake.org/Wiki/CMake:How_To_Find_Libraries#Writing_find_modules
find_path(TINYXML2_INCLUDE_DIR tinyxml2.h
   /usr/include
   /usr/local/include
   ${CMAKE_SOURCE_DIR}/extlibs/TinyXML2/include
)

find_library(TINYXML2_LIBRARY tinyxml2
   /usr/lib
   /usr/local/lib
   ${CMAKE_SOURCE_DIR}/extlibs/TinyXML2/lib/${ARCHITECTURE})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TinyXML2 DEFAULT_MSG
                                  TINYXML2_INCLUDE_DIR TINYXML2_LIBRARY)

mark_as_advanced(TINYXML2_INCLUDE_DIR TINYXML2_LIBRARY)

set(TINYXML2_INCLUDE_DIRS ${TINYXML2_INCLUDE_DIR})
set(TINYXML2_LIBRARIES ${TINYXML2_LIBRARY})
