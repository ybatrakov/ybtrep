cmake_minimum_required(VERSION 3.0)

include_directories(${MAMA_ROOT_DIR}/include)
link_directories(${MAMA_ROOT_DIR}/lib)

add_executable(mamalistenc mamalistenc.c)
target_link_libraries(mamalistenc mama)
