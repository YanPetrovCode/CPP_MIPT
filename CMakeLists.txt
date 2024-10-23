cmake_minimum_required(VERSION 3.22)
project(mdfmker CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
#set()


cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(
${LIB_DIR}
)
add_subdirectory(06)
#add_subdirectory(lib/name_age)
add_subdirectory(08)
add_subdirectory(12/shape_primitives)   