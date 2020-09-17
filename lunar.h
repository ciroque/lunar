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
    double CalculatePositionOfSun(double julianDay);

private:
    const double PI = 3.1415926535897932384626433832795;
    const double RAD = (PI/180.0);
    const double SMALL_FLOAT = (1e-12);
};

#endif //LUNAR_LUNAR_H
