#ifndef LUNAR_LUNAR_H
#define LUNAR_LUNAR_H

#include <list>

enum Name {
    New = 0,
    WaningCrescent,
    ThirdQuarter,
    WaningGibbous,
    Full,
    WaxingGibbous,
    FirstQuarter,
    WaxingCrescent
};

struct Phase {
    int julianDay;
    double sunPosition;
    double moonPosition;
    int segment;
    double visible;
    Name name;
};

class Lunar {
public:
    static Phase GetMoonPhase(unsigned int year, unsigned int month, double day);

private:
    const double PI = 3.1415926535897932384626433832795;
    const double RAD = (PI/180.0);
    const double SMALL_FLOAT = (1e-12);

    double CalculateJulianDay(unsigned int year, unsigned int month, double day);
    double CalculatePositionOfSun(double julianDay);
    double CalculatePositionOfMoon(double julianDay, double sunPosition);
//    double CalculatePhaseOfMoon(double julianDay, double sunPosition, double moonPosition);
    void CalculatePhaseOfMoon(Phase *phase);
};

#endif //LUNAR_LUNAR_H
