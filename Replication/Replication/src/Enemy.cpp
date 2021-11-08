#include "../include/Game.h"

using namespace uqac::game;
using namespace uqac::network;

void Enemy::Write(Serializer& serializer)
{
	serializer.Write(position, MIN_POS, MAX_POS, ACCURACY_POS);
	serializer.Write(life, MIN_LIFE, MAX_LIFE);
	serializer.Write(rotation);
}

void Enemy::Read(Deserializer& deserializer, std::vector<char> buffer)
{
	position = deserializer.ReadVector3(buffer, MIN_POS, MAX_POS, ACCURACY_POS);
	life = deserializer.ReadInt(buffer, MIN_LIFE, MAX_LIFE);
	rotation = deserializer.ReadQuat(buffer);
}

int Enemy::GetDataSize()
{
	return 100;
}

void Enemy::PrintEnemyData()
{
	printf("position : x:%.3f, y:%.3f, z:%.3f\n", position.x, position.y, position.z);
	printf("rotation : x:%f, y:%f, z:%f, w:%f\n", rotation.x, rotation.y, rotation.z, rotation.w);
	printf("life : %d\n", life);
}
