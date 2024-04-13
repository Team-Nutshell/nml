#include "../include/mat3.h"
#include "../include/mat2.h"
#include "../include/mat4.h"
#include "../include/other.h"
#include <cmath>
#include <stdexcept>

namespace nml {

mat3::mat3(): x(0.0f), y(0.0f), z(0.0f) {}
mat3::mat3(float _value): x(_value), y(_value), z(_value) {}
mat3::mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz): x(_xx, _xy, _xz), y(_yx, _yy, _yz), z(_zx, _zy, _zz) {}
mat3::mat3(float _xx, float _xy, float _xz, float _yx, float _yy, float _yz, vec3 _z): x(_xx, _xy, _xz), y(_yx, _yy, _yz), z(_z) {}
mat3::mat3(float _xx, float _xy, float _xz, vec3 _y, float _zx, float _zy, float _zz): x(_xx, _xy, _xz), y(_y), z(_zx, _zy, _zz) {}
mat3::mat3(vec3 _x, float _yx, float _yy, float _yz, float _zx, float _zy, float _zz): x(_x), y(_yx, _yy, _yz), z(_zx, _zy, _zz) {}
mat3::mat3(float _xx, float _xy, float _xz, vec3 _y, vec3 _z): x(_xx, _xy, _xz), y(_y), z(_z) {}
mat3::mat3(vec3 _x, vec3 _y, float _zx, float _zy, float _zz): x(_x), y(_y), z(_zx, _zy, _zz) {}
mat3::mat3(vec3 _x, float _yx, float _yy, float _yz, vec3 _z): x(_x), y(_yx, _yy, _yz), z(_z) {}
mat3::mat3(vec3 _x, vec3 _y, vec3 _z): x(_x), y(_y), z(_z) {}
mat3::mat3(const float* _ptr): x(_ptr), y(_ptr + 3), z(_ptr + 6) {}
mat3::mat3(mat4 _mat): x(_mat.x), y(_mat.y), z(_mat.z) {}

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

mat3& mat3::operator*=(const mat3& other) {
	mat3 tmp(vec3(x.x * other.x.x + y.x * other.x.y + z.x * other.x.z,
			x.y * other.x.x + y.y * other.x.y + z.y * other.x.z,
			x.z * other.x.x + y.z * other.x.y + z.z * other.x.z),
		vec3(x.x * other.y.x + y.x * other.y.y + z.x * other.y.z,
			x.y * other.y.x + y.y * other.y.y + z.y * other.y.z,
			x.z * other.y.x + y.z * other.y.y + z.z * other.y.z),
		vec3(x.x * other.z.x + y.x * other.z.y + z.x * other.z.z,
			x.y * other.z.x + y.y * other.z.y + z.y * other.z.z,
			x.z * other.z.x + y.z * other.z.y + z.z * other.z.z));

	x = tmp.x;
	y = tmp.y;
	z = tmp.z;

	return *this;
}

mat3& mat3::operator*=(const float other) {
	x *= other;
	y *= other;
	z *= other;

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

std::array<std::pair<float, vec3>, 3> mat3::eigen() const {
	const bool xyIsZero = (x.y > -0.0001f) && (x.y < 0.0001f);
	const bool yzIsZero = (y.z > -0.0001f) && (y.z < 0.0001f);
	const bool xzIsZero = (x.z > -0.0001f) && (x.z < 0.0001f);

	float eigenvalue1;
	float eigenvalue2;
	float eigenvalue3;

	if (xyIsZero && yzIsZero && xzIsZero) {
		eigenvalue1 = x.x;
		eigenvalue2 = y.y;
		eigenvalue3 = z.z;
	}
	else if (xyIsZero && xzIsZero) {
		const float halfyyMinuszz = (y.y - z.z) / 2.0f;

		eigenvalue1 = x.x;
		eigenvalue2 = ((y.y + z.z) / 2.0f) + std::sqrt((halfyyMinuszz * halfyyMinuszz) + (y.z * y.z));
		eigenvalue3 = ((y.y + z.z) / 2.0f) - std::sqrt((halfyyMinuszz * halfyyMinuszz) + (y.z * y.z));
	}
	else if (xyIsZero && yzIsZero) {
		const float halfxxMinuszz = (x.x - z.z) / 2.0f;

		eigenvalue1 = ((x.x + z.z) / 2.0f) + std::sqrt((halfxxMinuszz * halfxxMinuszz) + (x.z * x.z));
		eigenvalue2 = y.y;
		eigenvalue3 = ((x.x + z.z) / 2.0f) - std::sqrt((halfxxMinuszz * halfxxMinuszz) + (x.z * x.z));
	}
	else if (yzIsZero && xzIsZero) {
		const float halfxxMinusyy = (x.x - y.y) / 2.0f;

		eigenvalue1 = ((x.x + y.y) / 2.0f) + std::sqrt((halfxxMinusyy * halfxxMinusyy) + (x.y * x.y));
		eigenvalue2 = ((x.x + y.y) / 2.0f) - std::sqrt((halfxxMinusyy * halfxxMinusyy) + (x.y * x.y));
		eigenvalue3 = z.z;
	}
	else { // General case
		const float alpha = x.x + y.y + z.z;
		const float beta = (x.y * x.y) + (x.z * x.z) + (y.z * y.z) - (x.x * y.y) - (y.y * z.z) - (z.z * x.x);
		const float gamma = (x.x * y.y * z.z) + (2.0f * x.y * y.z * x.z) - (x.x * y.z * y.z) - (x.y * x.y * z.z) - (x.z * x.z * y.y);

		const float alphaOver3 = alpha / 3.0f;

		const float p = -(((3.0f * beta) + (alpha * alpha)) / 3.0f);
		const float q = -(gamma + ((2.0f * alpha * alpha * alpha) / 27.0f) + ((alpha * beta) / 3.0f));

		const float pOver3 = std::abs(p) / 3.0f;

		const float theta = std::acos(-(q / (2.0f * std::sqrt(pOver3 * pOver3 * pOver3))));

		eigenvalue1 = alphaOver3 + (2.0f * std::sqrt(pOver3) * std::cos(theta / 3.0f));
		eigenvalue2 = alphaOver3 - (2.0f * std::sqrt(pOver3) * std::cos((theta - PI) / 3.0f));
		eigenvalue3 = alphaOver3 - (2.0f * std::sqrt(pOver3) * std::cos((theta + PI) / 3.0f));
	}

	const mat3 eigenvalueMatrix = mat3(vec3(eigenvalue1, 0.0f, 0.0f), vec3(0.0f, eigenvalue2, 0.0f), vec3(0.0f, 0.0f, eigenvalue3));
	const mat3 b = *this - eigenvalueMatrix;

	vec3 eigenvector1;
	vec3 eigenvector2;
	vec3 eigenvector3;

	if (xyIsZero && yzIsZero && xzIsZero) {
		eigenvector1 = vec3(1.0f, 0.0f, 0.0f);
		eigenvector2 = vec3(0.0f, 1.0f, 0.0f);
		eigenvector3 = vec3(0.0f, 0.0f, 1.0f);
	}
	else if (xyIsZero && xzIsZero) {
		eigenvector1 = vec3(1.0f, 0.0f, 0.0f);
		eigenvector2 = vec3(0.0f, -(b.y.z / std::sqrt((b.y.y * b.y.y) + (b.y.z * b.y.z))), (b.y.y / std::sqrt((b.y.y * b.y.y) + (b.y.z * b.y.z))));
		eigenvector3 = vec3(0.0f, -(b.y.y / std::sqrt((b.y.y * b.y.y) + (b.y.z * b.y.z))), -(b.y.z / std::sqrt((b.y.y * b.y.y) + (b.y.z * b.y.z))));
	}
	else if (xyIsZero && yzIsZero) {
		eigenvector1 = vec3(0.0f, 1.0f, 0.0f);
		eigenvector2 = vec3(-(b.x.z / std::sqrt((b.x.x * b.x.x) + (b.x.z * b.x.z))), 0.0f, (b.x.x / std::sqrt((b.x.x * b.x.x) + (b.x.z * b.x.z))));
		eigenvector3 = vec3((b.x.x / std::sqrt((b.x.x * b.x.x) + (b.x.z * b.x.z))), 0.0f, (b.x.z / std::sqrt((b.x.x * b.x.x) + (b.x.z * b.x.z))));
	}
	else if (yzIsZero && xzIsZero) {
		eigenvector1 = vec3(0.0f, 0.0f, 1.0f);
		eigenvector2 = vec3(-(b.x.y / std::sqrt((b.x.x * b.x.x) + (b.x.y * b.x.y))), (b.x.x / std::sqrt((b.x.x * b.x.x) + (b.x.y * b.x.y))), 0.0f);
		eigenvector3 = vec3(-(b.x.x / std::sqrt((b.x.x * b.x.x) + (b.x.y * b.x.y))), -(b.x.y / std::sqrt((b.x.x * b.x.x) + (b.x.y * b.x.y))), 0.0f);
	}
	else { // General case
		if (((((b.x.x * b.y.z) - (b.x.z * b.x.y)) * b.x.z) != 0.0f) || ((((b.x.y * b.x.y) - (b.x.x * b.y.y)) * b.x.z) != 0.0f)) {
			const float Q = ((b.x.x * b.y.z) - (b.x.z * b.x.y)) / ((b.x.y * b.x.y) - (b.x.x * b.y.y));
			const float R = ((b.x.y * b.x.y) - (b.x.x * b.y.y)) / ((b.x.x * b.y.z) - (b.x.z * b.x.y));
			const float Pn = -(((b.y.z * Q) + b.z.z) / b.x.z);
			const float Pm = -((b.y.z + (b.z.z * R)) / b.x.z);

			const float n = 1.0f / std::sqrt((Pn * Pn) + (Q * Q) + 1.0f);
			const float m = 1.0f / std::sqrt((Pm * Pm) + 1.0f + (R * R));

			eigenvector1 = vec3(Pn * n, Q * n, n);
			eigenvector2 = vec3(Pm * m, m, R * m);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.x * b.z.z) - (b.x.z * b.x.z)) * b.x.y) != 0.0f) || ((((b.x.y * b.x.z) - (b.x.x * b.y.z)) * b.x.y) != 0.0f)) {
			const float Q = ((b.x.x * b.z.z) - (b.x.z * b.x.z)) / ((b.x.y * b.x.z) - (b.x.x * b.y.z));
			const float R = ((b.x.y * b.x.z) - (b.x.x * b.y.z)) / ((b.x.x * b.z.z) - (b.x.z * b.x.z));
			const float Pn = -(((b.y.y * Q) + b.y.z) / b.x.y);
			const float Pm = -((b.y.y + (b.y.z * R)) / b.x.y);

			const float n = 1.0f / std::sqrt((Pn * Pn) + (Q * Q) + 1.0f);
			const float m = 1.0f / std::sqrt((Pm * Pm) + 1.0f + (R * R));

			eigenvector1 = vec3(Pn * n, Q * n, n);
			eigenvector2 = vec3(Pm * m, m, R * m);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.y * b.z.z) - (b.y.z * b.x.z)) * b.x.x) != 0.0f) || ((((b.y.y * b.x.z) - (b.x.y * b.y.z)) * b.x.x) != 0.0f)) {
			const float Q = ((b.x.y * b.z.z) - (b.y.z * b.x.z)) / ((b.y.y * b.x.z) - (b.x.y * b.y.z));
			const float R = ((b.y.y * b.x.z) - (b.x.y * b.y.z)) / ((b.x.y * b.z.z) - (b.y.z * b.x.z));
			const float Pn = -(((b.x.y * Q) + b.x.z) / b.x.x);
			const float Pm = -((b.x.y + (b.x.z * R)) / b.x.x);

			const float n = 1.0f / std::sqrt((Pn * Pn) + (Q * Q) + 1.0f);
			const float m = 1.0f / std::sqrt((Pm * Pm) + 1.0f + (R * R));

			eigenvector1 = vec3(Pn * n, Q * n, n);
			eigenvector2 = vec3(Pm * m, m, R * m);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.y * b.y.z) - (b.x.z * b.y.y)) * b.y.z) != 0.0f) || ((((b.x.x * b.y.y) - (b.x.y * b.x.y)) * b.y.z) != 0.0f)) {
			const float P = ((b.x.y * b.y.z) - (b.x.z * b.y.y)) / ((b.x.x * b.y.y) - (b.x.y * b.x.y));
			const float R = ((b.x.x * b.y.y) - (b.x.y * b.x.y)) / ((b.x.y * b.y.z) - (b.x.z * b.y.y));
			const float Qn = -(((b.x.z * P) + b.z.z) / b.y.z);
			const float Ql = -((b.x.z + (b.z.z * R)) / b.y.z);

			const float n = 1.0f / std::sqrt((P * P) + (Qn * Qn) + 1.0f);
			const float l = 1.0f / std::sqrt(1.0f + (Ql * Ql) + (R * R));

			eigenvector1 = vec3(P * n, Qn * n, n);
			eigenvector2 = vec3(l, Ql * l, R * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.y * b.z.z) - (b.x.z * b.y.z)) * b.y.y) != 0.0f) || ((((b.x.x * b.y.z) - (b.x.y * b.x.z)) * b.y.y) != 0.0f)) {
			const float P = ((b.x.y * b.z.z) - (b.x.z * b.y.z)) / ((b.x.x * b.y.z) - (b.x.y * b.x.z));
			const float R = ((b.x.x * b.y.z) - (b.x.y * b.x.z)) / ((b.x.y * b.z.z) - (b.x.z * b.y.z));
			const float Qn = -(((b.x.y * P) + b.y.z) / b.y.y);
			const float Ql = -((b.x.y + (b.y.z * R)) / b.y.y);

			const float n = 1.0f / std::sqrt((P * P) + (Qn * Qn) + 1.0f);
			const float l = 1.0f / std::sqrt(1.0f + (Ql * Ql) + (R * R));

			eigenvector1 = vec3(P * n, Qn * n, n);
			eigenvector2 = vec3(l, Ql * l, R * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.y.y * b.z.z) - (b.y.z * b.y.z)) * b.x.y) != 0.0f) || ((((b.x.y * b.y.z) - (b.y.y * b.x.z)) * b.x.y) != 0.0f)) {
			const float P = ((b.y.y * b.z.z) - (b.y.z * b.y.z)) / ((b.x.y * b.y.z) - (b.y.y * b.x.z));
			const float R = ((b.x.y * b.y.z) - (b.y.y * b.x.z)) / ((b.y.y * b.z.z) - (b.y.z * b.y.z));
			const float Qn = -(((b.x.x * P) + b.x.z) / b.x.y);
			const float Ql = -((b.x.x + (b.x.z * R)) / b.x.y);

			const float n = 1.0f / std::sqrt((P * P) + (Qn * Qn) + 1.0f);
			const float l = 1.0f / std::sqrt(1.0f + (Ql * Ql) + (R * R));

			eigenvector1 = vec3(P * n, Qn * n, n);
			eigenvector2 = vec3(l, Ql * l, R * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.z * b.y.y) - (b.x.y * b.y.z)) * b.z.z) != 0.0f) || ((((b.x.x * b.y.z) - (b.x.z * b.x.y)) * b.z.z) != 0.0f)) {
			const float P = ((b.x.z * b.y.y) - (b.x.y * b.y.z)) / ((b.x.x * b.y.z) - (b.x.z * b.x.y));
			const float Q = ((b.x.x * b.y.z) - (b.x.z * b.x.y)) / ((b.x.z * b.y.y) - (b.x.y * b.y.z));
			const float Rm = -(((b.x.z * P) + b.y.z) / b.z.z);
			const float Rl = -((b.x.z + (b.y.z * Q)) / b.z.z);

			const float m = 1.0f / std::sqrt((P * P) + 1.0f + (Rm * Rm));
			const float l = 1.0f / std::sqrt(1.0f + (Q * Q) + (Rl * Rl));

			eigenvector1 = vec3(P * m, m, Rm * m);
			eigenvector2 = vec3(l, Q * l, Rl * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.x.z * b.y.z) - (b.x.y * b.z.z)) * b.y.z) != 0.0f) || ((((b.x.x * b.z.z) - (b.x.z * b.x.z)) * b.y.z) != 0.0f)) {
			const float P = ((b.x.z * b.y.z) - (b.x.y * b.z.z)) / ((b.x.x * b.z.z) - (b.x.z * b.x.z));
			const float Q = ((b.x.x * b.z.z) - (b.x.z * b.x.z)) / ((b.x.z * b.y.z) - (b.x.y * b.z.z));
			const float Rm = -(((b.x.y * P) + b.y.y) / b.y.z);
			const float Rl = -((b.x.y + (b.y.y * Q)) / b.y.z);

			const float m = 1.0f / std::sqrt((P * P) + 1.0f + (Rm * Rm));
			const float l = 1.0f / std::sqrt(1.0f + (Q * Q) + (Rl * Rl));

			eigenvector1 = vec3(P * m, m, Rm * m);
			eigenvector2 = vec3(l, Q * l, Rl * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
		else if (((((b.y.z * b.y.z) - (b.y.y * b.z.z)) * b.x.z) != 0.0f) || ((((b.x.y * b.z.z) - (b.y.z * b.x.z)) * b.x.z) != 0.0f)) {
			const float P = ((b.y.z * b.y.z) - (b.y.y * b.z.z)) / ((b.x.y * b.z.z) - (b.y.z * b.x.z));
			const float Q = ((b.x.y * b.z.z) - (b.y.z * b.x.z)) / ((b.y.z * b.y.z) - (b.y.y * b.z.z));
			const float Rm = -(((b.x.x * P) + b.x.y) / b.x.z);
			const float Rl = -((b.x.x + (b.x.y * Q)) / b.x.z);

			const float m = 1.0f / std::sqrt((P * P) + 1.0f + (Rm * Rm));
			const float l = 1.0f / std::sqrt(1.0f + (Q * Q) + (Rl * Rl));

			eigenvector1 = vec3(P * m, m, Rm * m);
			eigenvector2 = vec3(l, Q * l, Rl * l);
			eigenvector3 = cross(eigenvector1, eigenvector2);
		}
	}

	return { std::pair<float, vec3>(eigenvalue1, eigenvector1), std::pair<float, vec3>(eigenvalue2, eigenvector2), std::pair<float, vec3>(eigenvalue3, eigenvector3) };
}

float* mat3::data() {
	return x.data();
}

mat3 mat3::identity() {
	return mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

mat3 operator+(mat3 lhs, const mat3& rhs) {
	lhs += rhs;

	return lhs;
}

mat3 operator-(mat3 lhs, const mat3& rhs) {
	lhs -= rhs;

	return lhs;
}

mat3 operator*(mat3 lhs, const mat3& rhs) { 
	lhs *= rhs;

	return lhs;
}

vec3 operator*(mat3 lhs, const vec3& rhs) {
	return vec3(lhs.x.x * rhs.x + lhs.y.x * rhs.y + lhs.z.x * rhs.z,
		lhs.x.y * rhs.x + lhs.y.y * rhs.y + lhs.z.y * rhs.z,
		lhs.x.z * rhs.x + lhs.y.z * rhs.y + lhs.z.z * rhs.z);
}

mat3 operator*(mat3 lhs, const float rhs) {
	lhs *= rhs;

	return lhs;
}

mat3 operator*(float lhs, const mat3& rhs) {
	return (rhs * lhs);
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
	const float determinant = mat.det();

	const mat3 t = transpose(mat);
	const float a = mat2(t.y.y, t.y.z, t.z.y, t.z.z).det();
	const float b = mat2(t.y.x, t.y.z, t.z.x, t.z.z).det() * -1.0f;
	const float c = mat2(t.y.x, t.y.y, t.z.x, t.z.y).det();
	const float d = mat2(t.x.y, t.x.z, t.z.y, t.z.z).det() * -1.0f;
	const float e = mat2(t.x.x, t.x.z, t.z.x, t.z.z).det();
	const float f = mat2(t.x.x, t.x.y, t.z.x, t.z.y).det() * -1.0f;
	const float g = mat2(t.x.y, t.x.z, t.y.y, t.y.z).det();
	const float h = mat2(t.x.x, t.x.z, t.y.x, t.y.z).det() * -1.0f;
	const float i = mat2(t.x.x, t.x.y, t.y.x, t.y.y).det();

	const mat3 adj = mat3(a, b, c, d, e, f, g, h, i);

	return ((1.0f / determinant) * adj);
}

mat3 translate(const vec2& translation) {
	return mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, translation.x, translation.y, 1.0f);
}

mat3 rotate(const float angle) {
	const float cosTheta = std::cos(angle);
	const float sinTheta = std::sin(angle);
	
	return mat3(cosTheta, sinTheta, 0.0f, -sinTheta, cosTheta, 0.0f, 0.0f, 0.0f, 1.0f);
}

mat3 scale(const vec2& scaling) {
	return mat3(scaling.x, 0.0f, 0.0f, 0.0f, scaling.y, 0.0f, 0.0f, 0.0f, 1.0f);
}

std::string to_string(const mat3& mat) {
	return ("[" + to_string(mat.x) + ", " + to_string(mat.y) + ", " + to_string(mat.z) + "]");
}

}