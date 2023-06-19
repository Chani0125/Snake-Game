#ifndef _POINT_
#define _POINT_

struct Point
{
    int x;
    int y;

    Point(int x=0, int y=0) : x(x), y(y) {}

    bool operator<(const Point &p) const
    {
        if (x != p.x)
            return x < p.x;
        else
            return y < p.y;
    }

    bool operator==(const Point &p) const
    {
        return (x == p.x && y == p.y);
    }
};

#endif