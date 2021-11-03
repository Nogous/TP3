#pragma once

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;

	Quaternion() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
	Quaternion(int x, int y, int z, int w) : x(x), y(y), z(z), w(w){}
	Quaternion(float x, int y, int z, int w) : x(x), y(y), z(z), w(w){}
	Quaternion(int x, float y, int z, int w) : x(x), y(y), z(z), w(w){}
	Quaternion(int x, int y, float z, int w) : x(x), y(y), z(z), w(w){}
	Quaternion(int x, int y, int z, float w) : x(x), y(y), z(z), w(w){}
	Quaternion(float x, float y, int z, int w) : x(x), y(y), z(z), w(w) {}
	Quaternion(float x, int y, float z, int w) : x(x), y(y), z(z), w(w) {}
	Quaternion(float x, int y, int z, float w) : x(x), y(y), z(z), w(w) {}
	Quaternion(float x, float y, float z, int w) : x(x), y(y), z(z), w(w) {}
	Quaternion(float x, float y, int z, float w) : x(x), y(y), z(z), w(w) {}
	Quaternion(int x, float y, float z, int w) : x(x), y(y), z(z), w(w) {}
	Quaternion(int x, float y, int z, float w) : x(x), y(y), z(z), w(w) {}
	Quaternion(int x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	Quaternion(int x, int y, float z, float w) : x(x), y(y), z(z), w(w) {}
};