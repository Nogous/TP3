add_executable (Replication "src/Replication.cpp" "include/Replication.h" "include/NetworkObject.h" "src/Player.cpp" "include/Player.h"    "include/Enemy.h" "src/Enemy.cpp" "include/LinkingContext.h" "src/LinkingContext.cpp" "include/ClassRegistry.h" "src/ClassRegistry.cpp" "src/ReplicationManager.cpp" "include/ReplicationManager.h")

target_link_libraries(Replication PUBLIC Deserializer)
target_link_libraries(Replication PUBLIC UQACNetwork)
