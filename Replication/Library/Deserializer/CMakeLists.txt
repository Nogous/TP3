add_Library(
	Deserializer
	src/DataTransmitter.h
	src/DataTransmitter.cpp
	src/Deserializer.h
	src/Deserializer.cpp
	src/framework.h
	src/Player.h
	src/Player.cpp
	src/Quaternion.h
	src/Serializer.h
	src/Vector3.h
)

target_include_directories(Deserializer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")