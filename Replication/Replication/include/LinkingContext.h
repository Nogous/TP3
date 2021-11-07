#pragma once
#include <map>
#include "NetworkObject.h"

namespace uqac::network
{
	class LinkingContext
	{
	public:
		std::map<int, NetworkObject*> NetworkObjects;

	private:

	};
}