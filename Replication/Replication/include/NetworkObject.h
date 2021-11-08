#include <Deserializer.h>
#include <Serializer.h>

namespace uqac::network {

	class NetworkObject
	{
	public:
		
		enum
		{
			PLAYER = 0,
			ENEMY
		};

		int mClassId;

		NetworkObject();
		~NetworkObject() = default;

		virtual void Read(Deserializer& deserializer, std::vector<char> buffer) {}
		virtual void Write(Serializer& serializer) {}
	};
}

