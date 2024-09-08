#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float x, float y): x(x), y(y) {}

bool Vec2::operator == (const Vec2 & other_vec) const
{
    return (x == other_vec.x && y == other_vec.y);
}

bool Vec2::operator != (const Vec2 & other_vec) const
{
    return (x != other_vec.x || y != other_vec.y);
}

Vec2 Vec2::operator + (const Vec2 & other_vec) const
{
    return Vec2(x + other_vec.x, y + other_vec.y);
}

Vec2 Vec2::operator - (const Vec2 & other_vec) const
{
    return Vec2(x - other_vec.x, y - other_vec.y);
}

Vec2 Vec2::operator * (const Vec2 & other_vec) const
{
    return Vec2(x * other_vec.x, y * other_vec.y);
}

Vec2 Vec2::operator / (const Vec2 & other_vec) const
{
    return Vec2(x / other_vec.x, y / other_vec.y);
}

void Vec2::operator += (const Vec2 & other_vec)
{
    x += other_vec.x;
    y += other_vec.y;
}

void Vec2::operator -= (const Vec2 & other_vec)
{
    x -= other_vec.x;
    y -= other_vec.y;
}

void Vec2::operator *= (const Vec2 & other_vec)
{
    x *= other_vec.x;
    y *= other_vec.y;
}

void Vec2::operator /= (const Vec2 & other_vec)
{
    x /= other_vec.x;
    y /= other_vec.y;
}

float Vec2::dist(const Vec2 & other_vec) const
{
    float dif_x = other_vec.x - x;
    float dif_y = other_vec.y - y;
    return std::sqrt(dif_x*dif_x + dif_y*dif_y);
}