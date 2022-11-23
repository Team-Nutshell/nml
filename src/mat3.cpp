#include "../include/mat3.h"
#include "../include/mat2.h"
#include <cmath>
#include <stdexcept>

namespace nml {

mat3::mat3(): x(vec3(1.0f, 0.0f, 0.0f)), y(vec3(0.0f, 1.0f, 0.0f)), z(vec3(0.0f, 0.0f, 1.0f)) {}
mat3::mat3(float _xxxyxzyxyyyzzxzyzz): x(vec3(_xxxyxzyxyyyzzxzyzz)), y(vec3(_xxxyxzyxyyyzzxzyzz)), z(vec3(_xxxyxzyxyyyzzxzyzz)) {}
mat3::mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz): x(vec3(_xx, _xy, _xz)), y(vec3(_yx, _yy, _yz)), z(vec3(_zx, _zy, _zz)) {}
mat3::mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, vec3 _zxzyzz): x(vec3(_xx, _xy, _xz)), y(vec3(_yx, _yy, _yz)), z(_zxzyzz) {}
mat3::mat3(float _xx, float _xy, float _xz, vec3 _yxyyyz, float _zx, float _zy, float _zz): x(vec3(_xx, _xy, _xz)), y(_yxyyyz), z(vec3(_zx, _zy, _zz)) {}
mat3::mat3(vec3 _xxxyxz, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz): x(_xxxyxz), y(vec3(_yx, _yy, _yz)), z(vec3(_zx, _zy, _zz)) {}
mat3::mat3(float _xx, float _xy, float _xz, vec3 _yxyyyz, vec3 _zxzyzz): x(vec3(_xx, _xy, _xz)), y(_yxyyyz), z(_zxzyzz) {}
mat3::mat3(vec3 _xxxyxz, vec3 _yxyyyz, float _zx, float _zy, float _zz): x(_xxxyxz), y(_yxyyyz), z(vec3(_zx, _zy, _zz)) {}
mat3::mat3(vec3 _xxxyxz, float _yx, float _yy, float _yz, vec3 _zxzyzz): x(_xxxyxz), y(vec3(_yx, _yy, _yz)), z(_zxzyzz) {}
mat3::mat3(vec3 _xxxyxz, vec3 _yxyyyz, vec3 _zxzyzz): x(_xxxyxz), y(_yxyyyz), z(_zxzyzz) {}

mat3& mat3::operator+=(const mat3& other) { 
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

mat3& mat3::operator-=(const mat3& other) { 
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

mat3& mat3::operator*=(const float other) {
	x *= other;
	y *= other;
	z *= other;

	return *this;
}

mat3& mat3::operator*=(const mat3& other) {
	mat3 tmp;
	tmp.x = vec3(x.x * other.x.x + y.x * other.x.y + z.x * other.x.z,
		x.y * other.x.x + y.y * other.x.y + z.y * other.x.z,
		x.z * other.x.x + y.z * other.x.y + z.z * other.x.z);
	tmp.y = vec3(x.x * other.y.x + y.x * other.y.y + z.x * other.y.z,
		x.y * other.y.x + y.y * other.y.y + z.y * other.y.z,
		x.z * other.y.x + y.z * other.y.y + z.z * other.y.z);
	tmp.z = vec3(x.x * other.z.x + y.x * other.z.y + z.x * other.z.z,
		x.y * other.z.x + y.y * other.z.y + z.y * other.z.z,
		x.z * other.z.x + y.z * other.z.y + z.z * other.z.z);

	x = tmp.x;
	y = tmp.y;
	z = tmp.z;

	return *this;
}

mat3& mat3::operator/=(const float other) {
	x /= other;
	y /= other;
	z /= other;

	return *this;
}

vec3& mat3::operator[](size_t index) {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else if (index == 2) { return z; }
	else { throw std::out_of_range("mat3::operator[]: index is out of range."); }
}

const vec3& mat3::operator[](size_t index) const {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else if (index == 2) { return z; }
	else { throw std::out_of_range("mat3::operator[]: index is out of range."); }
}

float mat3::det() const {
	return ((x.x * ((y.y * z.z) - (z.y * y.z))) -
		(y.x * ((x.y * z.z) - (z.y * x.z))) +
		(z.x *((x.y * y.z) - (y.y * x.z))));
}

float* mat3::data() {
	return x.data();
}

std::string mat3::to_string() const {
	return ("[" + x.to_string() + ", " + y.to_string() + ", " + z.to_string() + "]");
}

mat3 operator+(mat3 lhs, const mat3& rhs) {
	lhs += rhs;

	return lhs;
}

mat3 operator-(mat3 lhs, const mat3& rhs) {
	lhs -= rhs;

	return lhs;
}

mat3 operator*(mat3 lhs, const float rhs) {
	lhs *= rhs;

	return lhs;
}

mat3 operator*(float lhs, const mat3& rhs) {
	return rhs * lhs;
}

mat3 operator*(mat3 lhs, const mat3& rhs) { 
	lhs *= rhs;

	return lhs;
}

mat3 operator/(mat3 lhs, const float rhs) {
	lhs /= rhs;

	return lhs;
}

bool operator==(const mat3& lhs, const mat3& rhs) {
	return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z));
}

bool operator!=(const mat3& lhs, const mat3& rhs) {
	return !(lhs == rhs);
}

mat3 transpose(const mat3& mat) {
	return mat3(mat.x.x, mat.y.x, mat.z.x, mat.x.y, mat.y.y, mat.z.y, mat.x.z, mat.y.z, mat.z.z);
}

mat3 inverse(const mat3& mat) {
	float determinant = mat.det();
	if (determinant == 0.0f) {
		throw std::runtime_error("nml::inverse(mat3): matrix is not invertible.");
	}

	mat3 t = transpose(mat);
	float a = mat2(t.y.y, t.y.z, t.z.y, t.z.z).det();
	float b = mat2(t.y.x, t.y.z, t.z.x, t.z.z).det() * -1.0f;
	float c = mat2(t.y.x, t.y.y, t.z.x, t.z.y).det();
	float d = mat2(t.x.y, t.x.z, t.z.y, t.z.z).det() * -1.0f;
	float e = mat2(t.x.x, t.x.z, t.z.x, t.z.z).det();
	float f = mat2(t.x.x, t.x.y, t.z.x, t.z.y).det() * -1.0f;
	float g = mat2(t.x.y, t.x.z, t.y.y, t.y.z).det();
	float h = mat2(t.x.x, t.x.z, t.y.x, t.y.z).det() * -1.0f;
	float i = mat2(t.x.x, t.x.y, t.y.x, t.y.y).det();

	mat3 adj = mat3(a, b, c, d, e, f, g, h, i);

	return ((1.0f / determinant) * adj);
}

}