#pragma once

#include <cmath>

template <typename T>
class Vec2 {

public:
	explicit Vec2(T x, T y) :
		x(x),
		y(y)
	{};

	Vec2<T> operator+(const Vec2<T>& rhs) {
		return Vec2<T>{x + rhs.x, y + rhs.y};
	}

	Vec2<T>& operator+=(const Vec2<T>& rhs) {
		return *this = *this + rhs;;
	}
	
	Vec2<T> operator*(const T& rhs) {
		return Vec2<T>{x * rhs, y * rhs};
	}

	Vec2<T>& operator*=(const T& rhs) {
		return *this = *this * rhs;
	}

	Vec2<T> operator-(const Vec2<T>& rhs) {
		return Vec2<T>{x - rhs.x, y - rhs.y};
	}

	Vec2<T>& operator-=(const Vec2<T>& rhs) {
		return *this = *this - rhs;;
	}

	Vec2<T> operator/(const T& rhs) {
		return Vec2<T>{x / rhs, y / rhs};
	}

	Vec2<T>& operator/=(const T& rhs) {
		return *this = *this / rhs;
	}

	T GetLength() {
		return x * x + y * y;
	}

	float GetLengthNormalized() {
		return sqrt((float)GetLength());
	}

public:
	T x;
	T y;
};