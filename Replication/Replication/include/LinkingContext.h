#pragma once
#include <map>
#include <optional>
#ifndef  NETWORKOBJ_H
#define  NETWORKOBJ_H
#include "NetworkObject.h"
#endif
#include <memory>

namespace uqac::network
{
	class LinkingContext
	{
	public:

		int networkId = 0;

		std::map<int, NetworkObject*> NetworkObjectsID;
		std::map<NetworkObject*, int> NetworkObjects;

		void AddNetworkObject(int id, NetworkObject* obj);
		void RemoveNetworkObject(NetworkObject* obj);
		void AddNetworkObject(NetworkObject* obj);

		std::optional<int> GetID(NetworkObject* obj);
		std::optional<NetworkObject*> GetObject(int id);
	};
}