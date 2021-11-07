add_executable (Replication "src/Replication.cpp" "include/Replication.h" "include/NetworkObject.h" "src/Player.cpp" "include/Player.h"  "src/Game.cpp" "src/NetworkObject.cpp" "include/Enemy.h" "src/Enemy.cpp" "include/LinkingContext.h" "src/LinkingContext.cpp")

target_link_libraries(Replication PUBLIC Deserializer)
target_link_libraries(Replication PUBLIC UQACNetwork)
