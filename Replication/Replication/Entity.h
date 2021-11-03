namespace uqac {

	namespace game {

		static unsigned int ID = 0;

		class Entity
		{
		public:
			Entity() {
				entityID = ID;
				ID++;
			};
			~Entity() = default;

			unsigned int entityID;
		};
		
	}
}

