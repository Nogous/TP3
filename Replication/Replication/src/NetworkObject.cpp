#include "../include/LinkingContext.h"

using namespace uqac::network;

NetworkObject::NetworkObject()
{
	LinkingContext::GetInstance()->AddNetworkObject(this);
}
