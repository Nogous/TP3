#include "Game.h"

using namespace uqac::game;
Entity::Entity()
{
	entityID = ID;
	ID++;
	Game::GetInstance()->_entities.push_back(*this);
}
