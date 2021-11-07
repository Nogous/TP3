#include "../include/Game.h"

using namespace uqac::game;

NetworkObject::NetworkObject()
{
	entityID = ID;
	ID++;
	Game::GetInstance()->_entities.push_back(*this);
}
