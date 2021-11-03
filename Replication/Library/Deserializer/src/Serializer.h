#pragma once
#include <vector>
#include "Vector3.h"
#include "Quaternion.h"

namespace uqac {
	namespace network {
		class Serializer {

		private:
			std::vector<char> buffer;
			size_t position;
		public:
			Serializer();
			Serializer(int size);
			void ResizeBuffer(size_t size);

			template <class T>
			void SerializeData(const T data)
			{
				int dataSize = sizeof(data);
				if (buffer.size() + dataSize > buffer.capacity())
				{
					ResizeBuffer();
					SerializeData(data);
				}
				else
				{
					data.Write(buffer);
				}
			}

			void Write(int data, int min, int max);
			void Write(float data, float min, float max, int accuracy);
			void Write(Vector3 data, Vector3 min, Vector3 max, int accuracy);
			void Write(Quaternion data);

			std::vector<char> GetBuffer() { return buffer; }
		};
	}
}