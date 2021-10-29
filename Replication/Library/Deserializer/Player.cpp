#include "Player.h"

void Player::Write(Serializer& serializer)
{
	//serializer.Write(classId);
	serializer.Write(position, MIN_POS, MAX_POS, ACCURACY_POS);
	serializer.Write(size, MIN_SIZE, MAX_SIZE, ACCURACY_SIZE);
	serializer.Write(life, MIN_LIFE, MAX_LIFE);
	serializer.Write(armor, MIN_ARMOR, MAX_ARMOR);
	serializer.Write(money, MIN_MONEY,MAX_MONEY,ACCURACY_MONEY);
	//serializer.Write(rotation);
}

void Player::Read(Deserializer& deserializer, std::vector<char> buffer)
{
	position = deserializer.ReadVector3(buffer, MIN_POS, MAX_POS, ACCURACY_POS);
	size = deserializer.ReadVector3(buffer, MIN_SIZE, MAX_SIZE, ACCURACY_SIZE);
	life = deserializer.ReadInt(buffer, MIN_LIFE, MAX_LIFE);
	armor = deserializer.ReadInt(buffer, MIN_ARMOR, MAX_ARMOR);
	money = deserializer.ReadFloat(buffer, MIN_MONEY, MAX_MONEY, ACCURACY_MONEY);
	//rotation = deserializer.ReadQuat(buffer);
}

int Player::GetDataSize()
{
	return 100;
}

void Player::PrintPlayerData()
{
	printf("position : x:%.3f, y:%.3f, z:%.3f\n", position.x, position.y, position.z);
	printf("rotation : x:%f, y:%f, z:%f, w:%f\n", rotation.x,rotation.y,rotation.z, rotation.w);
	printf("size : x:%.3f, y:%.3f, z:%.3f\n", size.x, size.y, size.z);
	printf("life : %d\n", life);
	printf("armor : %d\n", armor);
	printf("money : %.2f\n", money);

}
