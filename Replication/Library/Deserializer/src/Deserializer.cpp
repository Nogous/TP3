#include "Deserializer.h"
#include "framework.h"
// A CHANGER
#include "../../../Replication/include/Game.h"
#include <iostream>

using namespace uqac::network;
using namespace uqac::game;

Deserializer::Deserializer()
{
	position = 0;
}

Deserializer::~Deserializer()
{
}

void Deserializer::ReadData(std::vector<char> buffer)
{
	int classId = ReadInt(buffer, 0, Game::GetInstance()->classCount);
	int entityId = ReadInt(buffer, 0, Game::MAX_ENTITY_COUNT);
	if (Game::GetInstance()->EntityExist(entityId))
	{
		Game::GetInstance()->GetEntity(entityId).Read(this,buffer);
	}
	else
	{
		if (Game::GetInstance()->classIds[classId].type() == typeid(Player))
		{
			Player p;
			p.Read(this, buffer);
		}
	}
}

int Deserializer::ReadInt(std::vector<char> buffer, int min, int max)
{
	size_t sizeMax = std::abs(max - min);
	if (sizeMax <= UINT8_MAX) {
		sizeMax = sizeof(uint8_t);
		unsigned char c[sizeof(uint8_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint8_t*)c), min);
	}
	else if (sizeMax <= UINT16_MAX) {
		sizeMax = sizeof(uint16_t);
		unsigned char c[sizeof(uint16_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint16_t*)c), min);
	}
	else if (sizeMax <= UINT32_MAX) {
		sizeMax = sizeof(uint32_t);
		unsigned char c[sizeof(uint32_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint32_t*)c), min);
	}

	return-1;
}

float Deserializer::ReadFloat(std::vector<char> buffer, float min, float max, int accuracy)
{
	size_t sizeMax = std::abs(max - min);

	if (sizeMax <= UINT8_MAX) {
		sizeMax = sizeof(uint8_t);
		unsigned char c[sizeof(uint8_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint8_t*)c), min, accuracy);
	}
	else if (sizeMax <= UINT16_MAX) {
		sizeMax = sizeof(uint16_t);
		unsigned char c[sizeof(uint16_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint16_t*)c), min, accuracy);
	}
	else if (sizeMax <= UINT32_MAX) {
		sizeMax = sizeof(uint32_t);
		unsigned char c[sizeof(uint32_t)];
		std::memcpy(c, buffer.data() + position, sizeMax);
		position += sizeMax;
		return Decompressor(((int)*(uint32_t*)c), min, accuracy);
	}
	return -1;
}

Vector3 Deserializer::ReadVector3(std::vector<char> buffer, Vector3 min, Vector3 max, int accuracy)
{
	float x = ReadFloat(buffer, min.x, max.x, accuracy);
	float y = ReadFloat(buffer, min.y, max.y, accuracy);
	float z = ReadFloat(buffer, min.z, max.z, accuracy);
	return Vector3(x,y,z);
}

Quaternion Deserializer::ReadQuat(std::vector<char> buffer)
{
	int index = ReadInt(buffer, 0,3);

	Quaternion q = Quaternion();

	switch (index)
	{
	case 0:
		q.y = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.z = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.w = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.x = std::sqrt(1 - (q.y * q.y + q.z * q.z + q.w * q.w));
		break;
	case 1:
		q.x = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.z = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.w = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.y = std::sqrt(1 - (q.x * q.x + q.z * q.z + q.w * q.w));
		break;
	case 2:
		q.x = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.y = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.w = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.z = std::sqrt(1 - (q.x * q.x + q.y * q.y + q.w * q.w));
		break;
	case 3:
		q.x = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.y = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.z = ReadFloat(buffer, -0.707, 0.707, 1000);
		q.z = std::sqrt(1 - (q.x * q.x + q.y * q.y + q.z * q.z));
		break;
	}
	return q;
}
