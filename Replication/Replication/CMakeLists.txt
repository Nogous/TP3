add_executable (Replication "Replication.cpp" "Replication.h" "Entity.h" "Player.cpp" "Player.h")

target_link_libraries(Replication PRIVATE Deserializer)
target_link_libraries(Replication PRIVATE Socket)
