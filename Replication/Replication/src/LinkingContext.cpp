#include "../include/LinkingContext.h"

using namespace uqac::network;

void LinkingContext::AddNetworkObject(int id, NetworkObject* obj)
{
	NetworkObjectsID.insert(std::pair<int, NetworkObject*>(id, obj));
	NetworkObjects.insert(std::pair<NetworkObject*, int>(obj, id));
}

void LinkingContext::RemoveNetworkObject(NetworkObject* obj)
{
	int id = NetworkObjects[obj];
	NetworkObjects.erase(obj);
	NetworkObjectsID.erase(id);
}

void LinkingContext::AddNetworkObject(NetworkObject* obj)
{
	NetworkObjectsID.insert(std::pair<int, NetworkObject*>(networkId, obj));
	NetworkObjects.insert(std::pair<NetworkObject*, int>(obj, networkId));

	networkId++;
}

std::optional<int> LinkingContext::GetID(NetworkObject* obj)
{
	if (NetworkObjects.count(obj))
		return NetworkObjects[obj];
	return {};
}
std::optional<NetworkObject*> LinkingContext::GetObject(int id)
{
	if (NetworkObjectsID.count(id))
		return NetworkObjectsID[id];
	return {};
}

