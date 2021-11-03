#include "Serializer.h"
#include "Deserializer.h"
#include "Vector3.h"
#include "Quaternion.h"
#include <string>
using namespace uqac::network;


namespace uqac {
	namespace game {
		class Player {

		private:

			const Vector3 MIN_POS = Vector3(-500, -500, 0);
			const Vector3 MAX_POS = Vector3(500, 500, 100);
			const int ACCURACY_POS = 1000;

			const Vector3 MIN_SIZE = Vector3::zero();
			const Vector3 MAX_SIZE = Vector3::one();
			const int ACCURACY_SIZE = 1000;

			const int MIN_LIFE = 0;
			const int MAX_LIFE = 300;

			const int MIN_ARMOR = 0;
			const int MAX_ARMOR = 50;

			const float MIN_MONEY = -99999.99f;
			const float MAX_MONEY = 99999.99f;
			const int ACCURACY_MONEY = 1000;

			const int MAX_NAME_SIZE = 128;


		public:
			Player(int life, float money) : life(life), money(money) {}
			Player(int life, float money, Vector3 position) : life(life), money(money), position(position) {}
			Player(int life, float money, Vector3 position, Quaternion rotation) : life(life), money(money), position(position), rotation(rotation) {}
			Player() = default;
			~Player() = default;

			int classId = 11;
			Vector3 position = Vector3();
			Quaternion rotation = Quaternion();
			Vector3 size = Vector3::one();
			int life;
			int armor = 0;
			float money = 0;
			std::string name;


			void Write(Serializer& serializer);
			void Read(Deserializer& deserializer, std::vector<char> buffer);
			int GetDataSize();
			void PrintPlayerData();
		};
	}
}