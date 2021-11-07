add_executable (Replication "Replication.cpp" "Replication.h" "NetworkObject.h" "Player.cpp" "Player.h"  "Game.cpp" "NetworkObject.cpp" "Enemy.h" "Enemy.cpp")

target_link_libraries(Replication PUBLIC Deserializer)
target_link_libraries(Replication PUBLIC UQACNetwork)
