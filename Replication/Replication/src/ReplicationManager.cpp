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

void ReplicationManager::CreateObject(int classId, int objectId)
{
	NetworkObject* object = ClassRegistry::GetInstance()->CreateObject(classId);

	lnkContext.AddNetworkObject(objectId,object);
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

void ReplicationManager::Update(Deserializer& d, std::vector<char> buffer)
{
	int objectId = d.ReadInt(buffer, 0, 500); //id object
	//protocole / id objet / id class  / valeurs
	if (auto str = lnkContext.GetObject(objectId))
	{
		d.ReadInt(buffer, 0, 10); //id class
		//L'objet Existe
		str.value()->Read(d, buffer); //valeur
	}
	else
	{
		//L'objet n'existe pas
		CreateObject(d.ReadInt(buffer, 0, 10),objectId); //id class
		if (auto str = lnkContext.GetObject(objectId))
		{
			str.value()->Read(d, buffer);
		}
		else
		{
			printf("Erreur lors de la création de l'objet");
		}
	}
}
