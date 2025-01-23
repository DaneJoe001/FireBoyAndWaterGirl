#include <iostream>
#include <cmath>

#include <util/util_vector.h>

UtilVector::UtilVector() :x(-1), y(-1) {}

UtilVector::UtilVector(double x, double y) :x(x), y(y) {}

void UtilVector::set_vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

double UtilVector::get_distance(const UtilVector& other) const
{
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}

bool UtilVector::is_within(const UtilVector& begin, const UtilVector& end)
{
    bool check_x = begin.x <= this->x && this->x <= end.x;
    bool check_y = begin.y <= this->y && this->y <= end.y;
    return check_x && check_y;
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
