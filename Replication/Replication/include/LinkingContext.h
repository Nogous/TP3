#pragma once
#include <map>
#include <optional>
#include "NetworkObject.h"
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

		static inline std::unique_ptr<LinkingContext> _singleton = nullptr;

		static LinkingContext* GetInstance();

	private:

	};
}