add_Library(
	Socket
	src/Connection.h
	src/Connection.cpp
	src/LibNetwork.h
	src/LibNetwork.cpp
	src/TCPConnection.h
	src/TCPConnection.cpp
	src/Terminal.h
	src/Terminal.cpp
	src/UDPConnection.h
	src/UDPConnection.cpp
)

target_include_directories(Socket PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")