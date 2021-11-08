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

void ReplicationManager::Update(Serializer& s)
{
	s.Write(0,0,5);

	for (auto a : replicatedObjects)
	{
		if (auto str = lnkContext.GetID(a))
		{
			s.Write(str.value(), 0, 500);
		}
		else
		{
			printf("ALED"); //Objet Inconnu
			break;
		}
		s.Write(a->mClassId,0,10);
		a->Write(s);
	}
}
