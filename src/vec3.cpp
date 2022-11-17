#include "../include/vec3.h"
#include "../include/vec2.h"
#include <cmath>

namespace nml {

vec3::vec3(): x(0.0f), y(0.0f), z(0.0f) {}
vec3::vec3(float _xyz): x(_xyz), y(_xyz), z(_xyz) {}
vec3::vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
vec3::vec3(float _x, vec2 _yz): x(_x), y(_yz.x), z(_yz.y) {}
vec3::vec3(vec2 _xy, float _z): x(_xy.x), y(_xy.y), z(_z) {}

float vec3::length() const {
	return std::sqrt((x * x) + (y * y) + (z * z));
}

float* vec3::data() {
	return &x;
}

std::string vec3::to_string() const {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}

vec3 normalize(const vec3& v) {
	float l = v.length();

	return (v / l);
}

float dot(const vec3& a, const vec3& b) {
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

vec3 cross(const vec3& a, const vec3& b) {
	return vec3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

vec3 reflect(const vec3& i, const vec3& n) {
	return (i - 2.0f * dot(n, i) * n);
}

vec3 refract(const vec3& i, const vec3& n, float eta) {
	float ndoti = dot(n, i);
	float k = 1.0f - eta * eta * (1.0f - ndoti * ndoti);
	if (k < 0.0f) {
		return vec3(0.0f);
	}
	else {
		return eta * i - (eta * ndoti + std::sqrt(k)) * n;
	}
}

}