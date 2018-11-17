cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(${CMAKE_C_COMPILER_ID})

include_directories(${MAMA_ROOT_DIR}/include)
include_directories(${MAMA_SRC_DIR}/mama/c_cpp/src/c)

add_definitions(-DMAMA_DLL -DBRIDGE)

add_subdirectory(transport)
add_subdirectory(payload)
add_subdirectory(examples)
