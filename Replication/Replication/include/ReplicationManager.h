#include <unordered_set>
#include "LinkingContext.h"
#include <Serializer.h>
#include <Deserializer.h>

namespace uqac::network {
	
	class ReplicationManager {

	public:

		std::unordered_set<NetworkObject*> replicatedObjects;
		LinkingContext lnkContext;

		void CreateObject(int classId);
		void Update(Serializer& s);
		void Update(Deserializer& s, std::vector<char> buffer);
	};
}