#pragma once
namespace uqac {
	namespace network {
		struct Vector3
		{
			float x;
			float y;
			float z;

			Vector3() {
				x = 0;
				y = 0;
				z = 0;
			}

			Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
			Vector3(int x, float y, float z) : x(x), y(y), z(z) {}
			Vector3(int x, float y, int z) : x(x), y(y), z(z) {}
			Vector3(int x, int y, float z) : x(x), y(y), z(z) {}
			Vector3(float x, int y, float z) : x(x), y(y), z(z) {}
			Vector3(float x, int y, int z) : x(x), y(y), z(z) {}
			Vector3(float x, float y, int z) : x(x), y(y), z(z) {}
			Vector3(int x, int y, int z) : x(x), y(y), z(z) {}

			static Vector3 zero() {
				return Vector3();
			}

			static Vector3 one() {
				return Vector3(1, 1, 1);
			}
		};
	}
}