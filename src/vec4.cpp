#include "../include/vec4.h"
#include "../include/vec2.h"
#include "../include/vec3.h"
#include <cmath>

namespace nml {

vec4::vec4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
vec4::vec4(float _xyzw): x(_xyzw), y(_xyzw), z(_xyzw), w(_xyzw) {}
vec4::vec4(float _x, float _y, float _z, float _w): x(_x), y(_y), z(_z), w(_w) {}
vec4::vec4(float _x, vec3 _yzw): x(_x), y(_yzw.x), z(_yzw.y), w(_yzw.z) {}
vec4::vec4(vec3 _xyz, float _w): x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w) {}
vec4::vec4(float _x, float _y, vec2 _zw): x(_x), y(_y), z(_zw.x), w(_zw.y) {}
vec4::vec4(float _x, vec2 _yz, float _w): x(_x), y(_yz.x), z(_yz.y), w(_w) {}
vec4::vec4(vec2 _xy, float _z, float _w): x(_xy.x), y(_xy.y), z(_z), w(_w) {}
vec4::vec4(vec2 _xy, vec2 _zw): x(_xy.x), y(_xy.y), z(_zw.x), w(_zw.y) {}

float vec4::length() const {
	return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

float* vec4::data() {
	return &x;
}

std::string vec4::to_string() const {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
}

vec4 normalize(const vec4& v) {
	float l = v.length();

	return (v / l);
}

float dot(const vec4& a, const vec4& b) {
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

vec4 reflect(const vec4& i, const vec4& n) {
	return (i - 2.0f * dot(n, i) * n);
}

vec4 refract(const vec4& i, const vec4& n, float eta) {
	float ndoti = dot(n, i);
	float k = 1.0f - eta * eta * (1.0f - ndoti * ndoti);
	if (k < 0.0f) {
		return vec4(0.0f);
	}
	else {
		return eta * i - (eta * ndoti + std::sqrt(k)) * n;
	}
}

}