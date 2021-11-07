#include "../include/Game.h"

using namespace uqac::game;

Game* Game::GetInstance()
{
	if (singleton == nullptr)
		singleton = std::make_unique<Game>();

	return singleton.get();
}

template<typename T>
void Game::Init()
{
	AddClassId(Player);
}

template<typename T>
void Game::AddClassId(T type)
{
	if (!classIds.find(type))
	{
		classIds[type.classId] = type;
		classCount++;
	}
}

bool Game::EntityExist(int id)
{
	std::vector<NetworkObject>::iterator it = _entities.begin();
	for (it; it != _entities.end(); it++)
	{
		if (it->entityID == id)
			return true;
	}
	return false;
}

NetworkObject uqac::game::Game::GetEntity(int id)
{
	std::vector<NetworkObject>::iterator it = _entities.begin();
	for (it; it != _entities.end(); it++)
	{
		if (it->entityID == id)
			return *it;
	}
}
