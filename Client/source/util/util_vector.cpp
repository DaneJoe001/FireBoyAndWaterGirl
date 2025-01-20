﻿#include <iostream>
#include <cmath>

#include <util/util_vector.h>

UtilVector::UtilVector() :x(-1), y(-1) 
{
    std::cout << "UtilVector()" << std::endl;
}

UtilVector::UtilVector(double x, double y) :x(x), y(y) 
{
    std::cout << "UtilVector(" << x << ", " << y << ")" << std::endl;
}

void UtilVector::set_vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

double UtilVector::get_distance(const UtilVector& other) const
{
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}

UtilVector UtilVector::operator+(const UtilVector& other) const
{
    return UtilVector(x + other.x, y + other.y);
}

UtilVector UtilVector::operator-(const UtilVector& other) const
{
    return UtilVector(x - other.x, y - other.y);
}

UtilVector UtilVector::operator*(const float& other) const
{
    return UtilVector(x * other, y * other);
}

UtilVector UtilVector::operator/(const float& other) const
{
    if (other == 0)
    {
        return UtilVector();
    }
    return UtilVector(x / other, y / other);
}

UtilVector& UtilVector::operator+=(const UtilVector& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

UtilVector& UtilVector::operator-=(const UtilVector& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

UtilVector& UtilVector::operator*=(const UtilVector& other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

UtilVector& UtilVector::operator/=(const UtilVector& other)
{
    if (other.x == 0 || other.y == 0)
    {
        return *this;
    }
    x /= other.x;
    y /= other.y;
    return *this;
}
