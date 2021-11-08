#ifndef  NETWORKOBJ_H
#define  NETWORKOBJ_H
#include "NetworkObject.h"
#endif
#include <Serializer.h>
#include <Deserializer.h>
#include <Vector3.h>
#include <Quaternion.h>


using namespace uqac::network;

namespace uqac::game {
	class Enemy : NetworkObject {

	private:

		const Vector3 MIN_POS = Vector3(-500, -500, 0);
		const Vector3 MAX_POS = Vector3(500, 500, 100);
		const int ACCURACY_POS = 1000;

		const int MIN_LIFE = 0;
		const int MAX_LIFE = 300;

	public:
		Enemy(int l, Vector3 p, Quaternion r) {
			life = life;
			position = p;
			rotation = r;
		}
		Enemy() = default;
		~Enemy() = default;

		Vector3 position = Vector3();
		Quaternion rotation = Quaternion();
		int life;

		int mClassId = ENEMY;

		void Write(Serializer& serializer) override;
		void Read(Deserializer& deserializer, std::vector<char> buffer) override;
		int GetDataSize();
		void PrintEnemyData();
	};

}