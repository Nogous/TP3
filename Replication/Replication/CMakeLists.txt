add_executable (Replication "Replication.cpp" "Replication.h" "Entity.h" "Player.cpp" "Player.h")

target_link_libraries(Replication PUBLIC Deserializer)
target_link_libraries(Replication PUBLIC UQACNetwork)
