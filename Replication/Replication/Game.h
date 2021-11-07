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
			static const int MAX_ENTITY_COUNT = 100;

			static Game* GetInstance();
			int classCount = 0;
			bool EntityExist(int id);
			Entity GetEntity(int id);

			template<typename T>
			void Init();
			template<typename T>
			void AddClassId(T type);

		};

		

		

	}
}