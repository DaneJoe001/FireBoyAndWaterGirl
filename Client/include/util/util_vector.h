#pragma once

class UtilVector
{
public:
    double x, y;
public:
    UtilVector();
    UtilVector(double x, double y);
    void set_vector(double x, double y);
    double get_distance(const UtilVector& other) const;
    bool is_within(const UtilVector& begin, const UtilVector& end);
    UtilVector operator+(const UtilVector& other) const;
    UtilVector operator-(const UtilVector& other) const;
    UtilVector operator*(const float& other) const;
    UtilVector operator/(const float& other) const;
    UtilVector& operator+=(const UtilVector& other);
    UtilVector& operator-=(const UtilVector& other);
    UtilVector& operator*=(const UtilVector& other);
    UtilVector& operator/=(const UtilVector& other);
};