add_Library(
	Deserializer
	src/DataTransmitter.h
	src/DataTransmitter.cpp
)

target_include_directories(Deserializer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")