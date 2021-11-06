#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <memory>
#include <any>
#include "Player.h"


namespace uqac {

	namespace game {

		class Game
		{
			
			static inline std::unique_ptr<Game> singleton = nullptr;
		
		public :
			std::unordered_map<int,std::any> classIds;

			Game() = default;
			~Game() = default;

			std::vector<Entity> _entities;
			
			static Game* GetInstance();
			int classCount = 0;
			bool EntityExist(Entity entity);
			
			template<typename T>
			void Init();
			template<typename T>
			void AddClassId(T type);

		};

		

		

	}
}