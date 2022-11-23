#include "../include/mat2.h"
#include "../include/vec2.h"
#include <cmath>
#include <stdexcept>

namespace nml {

mat2::mat2(): x(vec2(1.0f, 0.0f)), y(vec2(0.0f, 1.0f)) {}
mat2::mat2(float _xxxyyxyy): x(vec2(_xxxyyxyy)), y(vec2(_xxxyyxyy)) {}
mat2::mat2(float _xx, float _xy, float _yx, float _yy): x(vec2(_xx, _xy)), y(vec2(_yx, _yy)) {}
mat2::mat2(float _xx, float _xy, vec2 _yxyy): x(vec2(_xx, _xy)), y(_yxyy) {}
mat2::mat2(vec2 _xxxy, float _yx, float _yy): x(_xxxy), y(vec2(_yx, _yy)) {}
mat2::mat2(vec2 _xxxy, vec2 _yxyy): x(_xxxy), y(_yxyy) {}

mat2& mat2::operator+=(const mat2& other) { 
	x += other.x;
	y += other.y;

	return *this;
}

mat2& mat2::operator-=(const mat2& other) { 
	x -= other.x;
	y -= other.y;

	return *this;
}

mat2& mat2::operator*=(const float other) {
	x *= other;
	y *= other;

	return *this;
}

mat2& mat2::operator*=(const mat2& other) {
	mat2 tmp;
	tmp.x = vec2(x.x * other.x.x + y.x * other.x.y,
		x.y * other.x.x + y.y * other.x.y);
	tmp.y = vec2(x.x * other.y.x + y.x * other.y.y,
		x.y * other.y.x + y.y * other.y.y);

	x = tmp.x;
	y = tmp.y;

	return *this;
}

mat2& mat2::operator/=(const float other) {
	x /= other;
	y /= other;

	return *this;
}

vec2& mat2::operator[](size_t index) {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else { throw std::out_of_range("mat2::operator[]: index is out of range."); }
}

const vec2& mat2::operator[](size_t index) const {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else { throw std::out_of_range("mat2::operator[]: index is out of range."); }
}

float mat2::det() const {
	return (x.x * y.y -
		y.x * x.y);
}

float* mat2::data() {
	return x.data();
}

std::string mat2::to_string() const {
	return ("[" + x.to_string() + ", " + y.to_string() + "]");
}

mat2 operator+(mat2 lhs, const mat2& rhs) {
	lhs += rhs;

	return lhs;
}

mat2 operator-(mat2 lhs, const mat2& rhs) {
	lhs -= rhs;

	return lhs;
}

mat2 operator*(mat2 lhs, const float rhs) {
	lhs *= rhs;

	return lhs;
}

mat2 operator*(float lhs, const mat2& rhs) {
	return rhs * lhs;
}

mat2 operator*(mat2 lhs, const mat2& rhs) { 
	lhs *= rhs;

	return lhs;
}

mat2 operator/(mat2 lhs, const float rhs) {
	lhs /= rhs;

	return lhs;
}

bool operator==(const mat2& lhs, const mat2& rhs) {
	return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

bool operator!=(const mat2& lhs, const mat2& rhs) {
	return !(lhs == rhs);
}

mat2 transpose(const mat2& mat) {
	return mat2(mat.x.x, mat.y.x, mat.x.y, mat.y.y);
}

mat2 inverse(const mat2& mat) {
	float determinant = mat.det();
	if (determinant == 0.0f) {
		throw std::runtime_error("nml::inverse(mat2): matrix is not invertible.");
	}

	return ((1.0f / determinant) * mat2(mat.y.y, -mat.x.y, -mat.y.x, mat.x.x));
}

}