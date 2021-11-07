#include <memory>
#include <functional>
#include <map>
#include "NetworkObject.h"

namespace uqac::network {
	
	class ClassRegistry {

	private:

		static inline std::unique_ptr<ClassRegistry> _singleton = nullptr;
		std::map<int, std::function<NetworkObject*()>> registry;

	public:

		static ClassRegistry* GetInstance();
		template<typename T>
		void AddClassToRegistry(T t);
		NetworkObject* CreateObject(int classID);
	};
}
