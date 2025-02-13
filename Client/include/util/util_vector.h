#pragma once

#include <cmath>

/**
* @class UtilVector
* @brief 二维向量基类
**/
template<class T>
class UtilVector
{
public:
    T x, y;
public:
    /**
    * @brief 构造函数
    **/
    UtilVector() :x(-1), y(-1) {}
    /**
    * @brief 构造函数
    * @param x x坐标
    * @param y y坐标
    **/
    UtilVector(T x, T y) :x(x), y(y) {}
    /**
    * @brief 设置坐标
    * @param x x坐标
    * @param y y坐标
    **/
    void set_vector(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    /**
    * @brief 获取距离
    * @param other 另一个坐标
    * @return 距离
    **/
    double get_distance(const UtilVector& other) const
    {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }
    /**
    * @brief 判断是否在矩形内
    * @param begin 矩形左下角坐标
    * @param end 矩形右上角坐标
    * @return 是否在矩形内
    **/
    bool is_within(const UtilVector& begin, const UtilVector& end)
    {
        bool check_x = begin.x <= this->x && this->x <= end.x;
        bool check_y = begin.y <= this->y && this->y <= end.y;
        return check_x && check_y;
    }
    /**
    * @brief 重载+运算符
    * @param other 另一个坐标
    **/
    UtilVector operator+(const UtilVector& other) const
    {
        return UtilVector(x + other.x, y + other.y);
    }
    /**
    * @brief 重载-运算符
    * @param other 另一个坐标
    **/
    UtilVector operator-(const UtilVector& other) const
    {
        return UtilVector(x - other.x, y - other.y);
    }
    /**
    * @brief 重载*运算符
    * @param other 另一个坐标
    **/
    UtilVector operator*(const T& other) const
    {
        return UtilVector(x * other, y * other);
    }
    /**
    * @brief 重载/运算符
    * @param other 另一个坐标
    **/
    UtilVector operator/(const T& other) const
    {
        if (other == 0)
        {
            return UtilVector();
        }
        return UtilVector(x / other, y / other);
    }
    /**
    * @brief 重载+=运算符
    * @param other 另一个坐标
    **/
    UtilVector& operator+=(const UtilVector& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    /**
    * @brief 重载-=运算符
    * @param other 另一个坐标
    **/
    UtilVector& operator-=(const UtilVector& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    /**
    * @brief 重载*=运算符
    * @param other 另一个坐标
    **/
    UtilVector& operator*=(const UtilVector& other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    /**
    * @brief 重载/=运算符
    * @param other 另一个坐标
    **/
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