find_package(OpenGL REQUIRED)
find_package(GLFW REQUIRED)
find_package(TinyXML2 REQUIRED)

if (WIN32)
   add_definitions(-DWIN32_LEAN_AND_MEAN)
endif()
add_definitions(-DGLFW_DLL -DGLFW_INCLUDE_NONE)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${TINYXML2_INCLUDE_DIRS})
include_directories("../extlibs/glad/include")
include_directories("../include")
include_directories(".")

file(GLOB PGE_SOURCES "../extlibs/glad/src/glad.c"
                      "../include/PicoGameEngine/Core/*.hpp" "Core/*.hpp" "Core/*.cpp"
                      "../include/PicoGameEngine/Graphics/*.hpp" "Graphics/*.cpp"
                      "../include/PicoGameEngine/Utils/*.hpp" "Utils/*.cpp")

if (BUILD_SHARED_LIBS)
   add_definitions(-DPGE_BUILD_DLL)
   add_library(PicoGameEngine SHARED ${PGE_SOURCES})
else()
   add_library(PicoGameEngine STATIC ${PGE_SOURCES})
endif()

target_link_libraries(PicoGameEngine ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${TINYXML2_LIBRARIES})

install(TARGETS PicoGameEngine DESTINATION ${INSTALL_DIR})
if (WIN32)
   install(DIRECTORY "${CMAKE_SOURCE_DIR}/extlibs/GLFW/bin/${ARCHITECTURE}" DESTINATION ${INSTALL_DIR})
   install(DIRECTORY "${CMAKE_SOURCE_DIR}/extlibs/TinyXML2/bin/${ARCHITECTURE}" DESTINATION ${INSTALL_DIR})
endif()
