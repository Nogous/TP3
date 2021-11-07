#include "../include/ClassRegistry.h"

using namespace uqac::network;

ClassRegistry* ClassRegistry::GetInstance()
{
	if (_singleton == nullptr)
		_singleton = std::make_unique<ClassRegistry>();

	return _singleton.get();
}

template<typename T>
void ClassRegistry::AddClassToRegistry(T t)
{
	registry.insert(std::pair<int, std::function<NetworkObject*()>>(t::mClassId, t()));
}

NetworkObject* ClassRegistry::CreateObject(int id)
{
	if (registry.find(id) != registry.end())
		return registry.find(id)->second();
}

int ClassRegistry::GetRegistrySize()
{
	return registry.size();
}