cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_NAME)
string(REPLACE " " "_" ProjectId ${PROJECT_NAME})
project(${PROJECT_NAME})
include(win32)

file(GLOB SOURCES "*.cpp" "*.h" "../Shared/*.cpp" "../../include/*.h" "../../include/*.hpp")
add_library(${PROJECT_NAME} SHARED ${SOURCES})

include(win32_install)
