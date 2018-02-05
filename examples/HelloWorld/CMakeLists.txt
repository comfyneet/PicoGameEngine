if (BUILD_SHARED_LIBS)
   add_definitions(-DPGE_DLL)
endif()

include_directories("../../include")

file(GLOB HELLOWORLD_SOURCES "*.hpp" "*.cpp")

add_executable(HelloWorld ${HELLOWORLD_SOURCES})

target_link_libraries(HelloWorld PicoGameEngine)

install(TARGETS HelloWorld DESTINATION ${INSTALL_DIR})
