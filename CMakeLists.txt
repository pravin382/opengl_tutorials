# Project defination
cmake_minimum_required(VERSION 3.0)
project(hello_world)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# change here for source files
# set(SOURCES "${SRC_DIR}/shader1_main.cpp" "${SRC_DIR}/shader1.cpp" "${INCLUDE}/shader1.h")
set(SOURCES "${SRC_DIR}/camera_view.cpp" "${SRC_DIR}/shader1.cpp" "${INCLUDE}/shader1.h")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(EXE "main")

# Executable definition and properties
include_directories(${INCLUDE})
add_executable(${EXE} ${SOURCES})
target_include_directories(${EXE} PRIVATE "${SRC_DIR}")
set_property(TARGET ${EXE} PROPERTY CXX_STANDARD_11)

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${EXE} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${EXE} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${EXE} PRIVATE "GLFW_INCLUDE_NONE")

#glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${EXE} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${EXE} "glad" "${CMAKE_DL_LIBS}")

# stb
set(STB_DIR "${LIB_DIR}/stb")
add_library("stb" "${STB_DIR}/src/stb_image.cpp")
target_include_directories("stb" PRIVATE "${STB_DIR}/include")
target_include_directories(${EXE} PRIVATE "${STB_DIR}/include")
target_link_libraries(${EXE} "stb" "${CMAKE_DL_LIBS}")

