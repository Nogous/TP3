add_Library(
	Deserializer
	src/Deserializer.h
	src/Deserializer.cpp
	src/framework.h
	src/Quaternion.h
	src/Serializer.h
	src/Serializer.cpp
	src/Vector3.h
)

target_include_directories(Deserializer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")