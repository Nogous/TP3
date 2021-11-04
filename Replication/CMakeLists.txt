# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.19)

project (Replication)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory (Library)
add_subdirectory (Library/Deserializer)

add_subdirectory (Replication)
