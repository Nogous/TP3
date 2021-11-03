add_Library(
	Socket
	src/LibNetwork.h
	src/LibNetwork.cpp
)

target_include_directories(Socket PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")