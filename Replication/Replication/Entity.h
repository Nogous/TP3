namespace uqac {

	namespace game {

		static unsigned int ID = 0;

		class Entity
		{
		public:
			Entity();
			~Entity() = default;

			unsigned int entityID;
			virtual void Read(Deserializer* deserializer, std::vector<char> buffer) {}
		};
		
	}
}

