#include <Deserializer.h>
#include <Serializer.h>

namespace uqac::network {

	static unsigned int ID = 0;

	class NetworkObject
	{
	public:
		NetworkObject();
		~NetworkObject() = default;

		unsigned int entityID;
		virtual void Read(Deserializer* deserializer, std::vector<char> buffer) {}
		virtual void Write(Serializer& serializer) {}
	};
}

