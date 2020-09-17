#ifndef LUNAR_LUNAR_H
#define LUNAR_LUNAR_H

#include <list>

enum Direction {
    WAXING = 1,
    WANING = 2
};

struct Phase {
    Direction direction;
    double Visible;
};

class Lunar {
public:
    static std::list<Phase> GetMoonPhases();
    double CalculateJulianDay(int year, int month, double day);

private:
};

#endif //LUNAR_LUNAR_H
