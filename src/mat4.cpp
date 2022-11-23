#include "../include/mat4.h"
#include "../include/mat3.h"
#include <cmath>
#include <stdexcept>

namespace nml {

mat4::mat4(): x(1.0f, 0.0f, 0.0f, 0.0f), y(0.0f, 1.0f, 0.0f, 0.0f), z(0.0f, 0.0f, 1.0f, 0.0f), w(0.0f, 0.0f, 0.0f, 1.0f) {}
mat4::mat4(float _xxxyxzxwyxyyyzywzxzyzzzwwxwywzww): x(_xxxyxzxwyxyyyzywzxzyzzzwwxwywzww), y(_xxxyxzxwyxyyyzywzxzyzzzwwxwywzww), z(_xxxyxzxwyxyyyzywzxzyzzzwwxwywzww), w(_xxxyxzxwyxyyyzywzxzyzzzwwxwywzww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww): x(_xx, _xy, _xz, _xw), y(_yx, _yy, _yz, _yw), z(_zx, _zy, _zz, _zw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww): x(_xx, _xy, _xz, _xw), y(_yx, _yy, _yz, _yw), z(_zx, _zy, _zz, _zw), w(_wxwywzww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww): x(_xx, _xy, _xz, _xw), y(_yx, _yy, _yz, _yw), z(_zxzyzzzw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww): x(_xx, _xy, _xz, _xw), y(_yxyyyzyw), z(_zx, _zy, _zz, _zw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww): x(_xxxyxzxw), y(_yx, _yy, _yz, _yw), z(_zx, _zy, _zz, _zw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, vec4 _wxwywzww): x(_xx, _xy, _xz, _xw), y(_yx, _yy, _yz, _yw), z(_zxzyzzzw), w(_wxwywzww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww): x(_xx, _xy, _xz, _xw), y(_yxyyyzyw), z(_zx, _zy, _zz, _zw), w(_wxwywzww) {}
mat4::mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww): x(_xxxyxzxw), y(_yx, _yy, _yz, _yw), z(_zx, _zy, _zz, _zw), w(_wxwywzww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww): x(_xx, _xy, _xz, _xw), y(_yxyyyzyw), z(_zxzyzzzw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww): x(_xxxyxzxw), y(_yx, _yy, _yz, _yw), z(_zxzyzzzw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, float _wx, float _wy, float _wz, float _ww): x(_xxxyxzxw), y(_yxyyyzyw), z(_zx, _zy, _zz, _zw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(float _xx, float _xy, float _xz, float _xw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, vec4 _wxwywzww): x(_xx, _xy, _xz, _xw), y(_yxyyyzyw), z(_zxzyzzzw), w(_wxwywzww) {}
mat4::mat4(vec4 _xxxyxzxw, float _yx, float _yy, float _yz, float _yw, vec4 _zxzyzzzw, vec4 _wxwywzww): x(_xxxyxzxw), y(_yx, _yy, _yz, _yw), z(_zxzyzzzw), w(_wxwywzww) {}
mat4::mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, float _zx, float _zy, float _zz, float _zw, vec4 _wxwywzww): x(_xxxyxzxw), y(_yxyyyzyw), z(_zx, _zy, _zz, _zw), w(_wxwywzww) {}
mat4::mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, float _wx, float _wy, float _wz, float _ww): x(_xxxyxzxw), y(_yxyyyzyw), z(_zxzyzzzw), w(_wx, _wy, _wz, _ww) {}
mat4::mat4(vec4 _xxxyxzxw, vec4 _yxyyyzyw, vec4 _zxzyzzzw, vec4 _wxwywzww): x(_xxxyxzxw), y(_yxyyyzyw), z(_zxzyzzzw), w(_wxwywzww) {}

mat4& mat4::operator+=(const mat4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;

	return *this;
}

mat4& mat4::operator-=(const mat4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return *this;
}

mat4& mat4::operator*=(const float other) {
	x *= other;
	y *= other;
	z *= other;
	w *= other;

	return *this;
}

mat4& mat4::operator*=(const mat4& other) {
	mat4 tmp;
	tmp.x = vec4(x.x * other.x.x + y.x * other.x.y + z.x * other.x.z + w.x * other.x.w,
		x.y * other.x.x + y.y * other.x.y + z.y * other.x.z + w.y * other.x.w,
		x.z * other.x.x + y.z * other.x.y + z.z * other.x.z + w.z * other.x.w,
		x.w * other.x.x + y.w * other.x.y + z.w * other.x.z + w.w * other.x.w);
	tmp.y = vec4(x.x * other.y.x + y.x * other.y.y + z.x * other.y.z + w.x * other.y.w,
		x.y * other.y.x + y.y * other.y.y + z.y * other.y.z + w.y * other.y.w,
		x.z * other.y.x + y.z * other.y.y + z.z * other.y.z + w.z * other.y.w,
		x.z * other.y.x + y.z * other.y.y + z.z * other.y.z + w.w * other.y.w);
	tmp.z = vec4(x.x * other.z.x + y.x * other.z.y + z.x * other.z.z + w.x * other.z.w,
		x.y * other.z.x + y.y * other.z.y + z.y * other.z.z + w.y * other.z.w,
		x.z * other.z.x + y.z * other.z.y + z.z * other.z.z + w.z * other.z.w,
		x.w * other.z.x + y.w * other.z.y + z.w * other.z.z + w.w * other.z.w);
	tmp.w = vec4(x.x * other.w.x + y.x * other.w.y + z.x * other.w.z + w.x * other.w.w,
		x.y * other.w.x + y.y * other.w.y + w.y * other.w.z + w.y * other.w.w,
		x.z * other.w.x + y.z * other.w.y + w.z * other.w.z + w.z * other.w.w,
		x.w * other.w.x + y.w * other.w.y + w.w * other.w.z + w.w * other.w.w);

	x = tmp.x;
	y = tmp.y;
	z = tmp.z;
	w = tmp.w;

	return *this;
}

mat4& mat4::operator/=(const float other) {
	x /= other;
	y /= other;
	z /= other;
	w /= other;

	return *this;
}

vec4& mat4::operator[](size_t index) {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else if (index == 2) { return z; }
	else { throw std::out_of_range("mat4::operator[]: index is out of range."); }
}

const vec4& mat4::operator[](size_t index) const {
	if (index == 0) { return x; }
	else if (index == 1) { return y; }
	else if (index == 2) { return z; }
	else { throw std::out_of_range("mat4::operator[]: index is out of range."); }
}

float mat4::det() const {
	return (x.x * ((y.y * z.z * w.w) - (y.y * w.z * z.w) - (z.y * y.z * w.w) + (z.y * w.z * y.w) + (w.y * y.z * z.w) - (w.y * z.z * y.w)) -
		y.x * ((x.y * z.z * w.w) - (x.y * w.z * z.w) - (z.y * x.z * w.w) + (z.y * w.z * x.w) + (w.y * x.z * z.w) - (w.y * z.z * x.w)) +
		z.x * ((x.y * y.z * w.w) - (x.y * w.z * y.w) - (y.y * x.z * w.w) + (y.y * w.z * x.w) + (w.y * x.z * y.w) - (w.y * y.z * x.w)) -
		w.x * ((x.y * y.z * z.w) - (x.y * z.z * y.w) - (y.y * x.z * z.w) + (y.y * z.z * x.w) + (z.y * x.z * y.w) - (z.y * y.z * x.w)));
}

float* mat4::data() {
	return x.data();
}

std::string mat4::to_string() const {
	return ("[" + x.to_string() + ", " + y.to_string() + ", " + z.to_string() + ", " + w.to_string() + "]");
}

mat4 operator+(mat4 lhs, const mat4& rhs) {
	lhs += rhs;

	return lhs;
}

mat4 operator-(mat4 lhs, const mat4& rhs) {
	lhs -= rhs;

	return lhs;
}

mat4 operator*(mat4 lhs, const float rhs) {
	lhs *= rhs;

	return lhs;
}

mat4 operator*(float lhs, const mat4& rhs) {
	return rhs * lhs;
}

mat4 operator*(mat4 lhs, const mat4& rhs) { 
	lhs *= rhs;

	return lhs;
}

mat4 operator/(mat4 lhs, const float rhs) {
	lhs /= rhs;

	return lhs;
}

bool operator==(const mat4& lhs, const mat4& rhs) {
	return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z));
}

bool operator!=(const mat4& lhs, const mat4& rhs) {
	return !(lhs == rhs);
}

mat4 transpose(const mat4& mat) {
	return mat4(mat.x.x, mat.y.x, mat.z.x, mat.w.x, mat.x.y, mat.y.y, mat.z.y, mat.w.y, mat.x.z, mat.y.z, mat.z.z, mat.w.z, mat.x.w, mat.y.w, mat.z.w, mat.w.w);
}

mat4 inverse(const mat4& mat) {
	float determinant = mat.det();
	if (determinant == 0.0f) {
		throw std::runtime_error("nml::inverse(mat4): matrix is not invertible.");
	}

	mat4 t = transpose(mat);
	float a = mat3(t.y.y, t.y.z, t.y.w, t.z.y, t.z.z, t.z.w, t.w.y, t.w.z, t.w.w).det();
	float b = mat3(t.y.x, t.y.z, t.y.w, t.z.x, t.z.z, t.z.w, t.w.x, t.w.z, t.w.w).det() * -1.0f;
	float c = mat3(t.y.x, t.y.y, t.y.w, t.z.x, t.z.y, t.z.w, t.w.x, t.w.y, t.w.w).det();
	float d = mat3(t.y.x, t.y.y, t.y.z, t.z.x, t.z.y, t.z.z, t.w.x, t.w.y, t.w.z).det() * -1.0f;
	float e = mat3(t.x.y, t.x.z, t.x.w, t.z.y, t.z.z, t.z.w, t.w.y, t.w.z, t.w.w).det() * -1.0f;
	float f = mat3(t.x.x, t.x.z, t.x.w, t.z.x, t.z.z, t.z.w, t.w.x, t.w.z, t.w.w).det();
	float g = mat3(t.x.x, t.x.y, t.z.w, t.z.x, t.z.y, t.z.w, t.w.x, t.w.y, t.w.w).det() * -1.0f;
	float h = mat3(t.x.x, t.x.y, t.z.z, t.z.x, t.z.y, t.z.z, t.w.x, t.w.y, t.w.z).det();
	float i = mat3(t.x.y, t.x.z, t.x.w, t.y.y, t.y.z, t.y.w, t.w.y, t.w.z, t.w.w).det();
	float j = mat3(t.x.x, t.x.z, t.x.w, t.y.x, t.y.z, t.y.w, t.w.x, t.w.z, t.w.w).det() * -1.0f;
	float k = mat3(t.x.x, t.x.y, t.x.w, t.y.x, t.y.y, t.y.w, t.w.x, t.w.y, t.w.w).det();
	float l = mat3(t.x.x, t.x.y, t.x.z, t.y.x, t.y.y, t.y.z, t.w.x, t.w.y, t.w.z).det() * -1.0f;
	float m = mat3(t.x.y, t.x.z, t.x.w, t.y.y, t.y.z, t.y.w, t.z.y, t.z.z, t.z.w).det() * -1.0f;
	float n = mat3(t.x.x, t.x.z, t.x.w, t.y.x, t.y.z, t.y.w, t.z.x, t.z.z, t.z.w).det();
	float o = mat3(t.x.x, t.x.y, t.x.w, t.y.x, t.y.y, t.y.w, t.z.x, t.z.y, t.z.w).det() * -1.0f;
	float p = mat3(t.x.x, t.x.y, t.x.z, t.y.x, t.y.y, t.y.z, t.z.x, t.z.y, t.z.z).det();

	mat4 adj = mat4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);

	return ((1.0f / determinant) * adj);
}

}