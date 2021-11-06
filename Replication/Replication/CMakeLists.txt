add_executable (Replication "Replication.cpp" "Replication.h" "Entity.h" "Player.cpp" "Player.h"  "Game.cpp" "Entity.cpp")

target_link_libraries(Replication PUBLIC Deserializer)
target_link_libraries(Replication PUBLIC UQACNetwork)
