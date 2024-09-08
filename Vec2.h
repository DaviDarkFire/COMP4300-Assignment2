#pragma once

class Vec2
{
public:

    float x = 0;
    float y = 0;

    Vec2();
    Vec2(float x, float y);

    bool operator == (const Vec2 & other_vec) const;
    bool operator != (const Vec2 & other_vec) const;

    Vec2 operator + (const Vec2 & other_vec) const;
    Vec2 operator - (const Vec2 & other_vec) const;
    Vec2 operator / (const Vec2 & other_vec) const;
    Vec2 operator * (const Vec2 & other_vec) const;

    void operator += (const Vec2 & other_vec);
    void operator -= (const Vec2 & other_vec);
    void operator *= (const Vec2 & other_vec);
    void operator /= (const Vec2 & other_vec);

    float dist(const Vec2 & other_vec) const;
};