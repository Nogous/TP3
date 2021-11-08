#include <unordered_set>
#include "LinkingContext.h"

namespace uqac::network {
	
	class ReplicationManager {

	public:

		std::unordered_set<NetworkObject*> replicatedObjects;
		LinkingContext lnkContext;

		void CreateObject(int classId);
		void Update();
	};
}