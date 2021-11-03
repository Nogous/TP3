add_executable (Replication "Replication.cpp" "Replication.h")

target_link_libraries(Replication PRIVATE Deserializer)
target_link_libraries(Replication PRIVATE Socket)
