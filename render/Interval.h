#ifndef _INTERVAL_H_
#define _INTERVAL_H_
#include "rt.h"
class interval
{
public:
    double min, max;
    interval() : min(+infinity), max(-infinity)
    {
    }

    interval(double min, double max) : min(min), max(max)
    {
    }
    double size() const
    {
        return max - min;
    }

    bool contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }
    static const interval empty, universe;
};

#endif