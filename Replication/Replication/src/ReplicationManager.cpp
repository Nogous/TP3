#pragma once
#include "..\include\ReplicationManager.h"
#include "..\include\ClassRegistry.h"

using namespace uqac::network;

void ReplicationManager::CreateObject(int classId)
{
	NetworkObject* object = ClassRegistry::GetInstance()->CreateObject(classId);

	lnkContext.AddNetworkObject(object);
	replicatedObjects.insert(object);
}

void ReplicationManager::Update()
{

}