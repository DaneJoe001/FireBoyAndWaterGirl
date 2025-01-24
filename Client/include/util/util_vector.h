#pragma once

#include <cmath>

template<class T>
class UtilVector
{
public:
    T x, y;
public:
    UtilVector() :x(-1), y(-1) {}
    UtilVector(T x, T y) :x(x), y(y) {}
    void set_vector(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    double get_distance(const UtilVector& other) const
    {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }
    bool is_within(const UtilVector& begin, const UtilVector& end)
    {
        bool check_x = begin.x <= this->x && this->x <= end.x;
        bool check_y = begin.y <= this->y && this->y <= end.y;
        return check_x && check_y;
    }
    UtilVector operator+(const UtilVector& other) const
    {
        return UtilVector(x + other.x, y + other.y);
    }
    UtilVector operator-(const UtilVector& other) const
    {
        return UtilVector(x - other.x, y - other.y);
    }
    UtilVector operator*(const T& other) const
    {
        return UtilVector(x * other, y * other);
    }
    UtilVector operator/(const T& other) const
    {
        if (other == 0)
        {
            return UtilVector();
        }
        return UtilVector(x / other, y / other);
    }
    UtilVector& operator+=(const UtilVector& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    UtilVector& operator-=(const UtilVector& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    UtilVector& operator*=(const UtilVector& other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    UtilVector& operator/=(const UtilVector& other)
    {
        if (other.x == 0 || other.y == 0)
        {
            return *this;
        }
        x /= other.x;
        y /= other.y;
        return *this;
    }
};