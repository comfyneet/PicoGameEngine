find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(LibXml2 REQUIRED)

add_definitions(-DGLFW_DLL -DGLFW_INCLUDE_NONE)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW3_INCLUDE_DIRS})
include_directories(${LIBXML2_INCLUDE_DIR})
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

target_link_libraries(PicoGameEngine ${OPENGL_LIBRARIES} ${GLFW3_LIBRARIES} ${LIBXML2_LIBRARIES})
