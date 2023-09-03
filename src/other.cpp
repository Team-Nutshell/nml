#include "../include/other.h"

float nml::toRad(const float degrees) {
	return degrees * (PI / 180.0f);
}

float nml::toDeg(const float radians) {
	return radians * (180.0f / PI);
}