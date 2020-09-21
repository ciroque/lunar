#ifndef LUNAR_LUNAR_H
#define LUNAR_LUNAR_H

#include <array>
#include <string>

enum Segment {
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
    double visible;
    Segment segment;
};

class Lunar {
public:
    static Phase GetMoonPhase();
    static Phase GetMoonPhase(int julianDay);
    static Phase GetMoonPhase(unsigned int year, unsigned int month, double day);
    static const std::string GetSegmentName(int segment);

private:
    const double PI = 3.1415926535897932384626433832795;
    const double RAD = (PI/180.0);
    const double SMALL_FLOAT = (1e-12);

    int CalculateJulianDay(unsigned int year, unsigned int month, double day);
    double CalculatePositionOfSun(double julianDay);
    double CalculatePositionOfMoon(double julianDay, double sunPosition);
    void CalculatePhaseOfMoon(Phase *phase);
};

#endif //LUNAR_LUNAR_H
