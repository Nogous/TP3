#pragma once
#include <vector>
#include "Vector3.h"
#include "Quaternion.h"
namespace uqac {
	namespace network {
		class Deserializer
		{
		private:
			size_t position;

		public:
			Deserializer();
			~Deserializer();

			int ReadInt(std::vector<char> buffer, int min, int max);

			float ReadFloat(std::vector<char> buffer, float min, float max, int accuracy);

			Vector3 ReadVector3(std::vector<char> buffer, Vector3 min, Vector3 max, int accuracy);
			Quaternion ReadQuat(std::vector<char> buffer);
		};
	}
}