#ifndef LUNAR_LUNAR_H
#define LUNAR_LUNAR_H

#include <array>
#include <string>

enum Segment {
    New = 0,
    WaxingCrescent,
    FirstQuarter,
    WaxingGibbous,
    Full,
    WaningGibbous,
    ThirdQuarter,
    WaningCrescent,
};

struct Phase {
    int julianDay;
    double sunPosition;
    double moonPosition;
    double visible;
    enum Segment segment;
};

class Lunar {
public:
    constexpr static const int EPOCH = 2444238; // [2444238.5] We do not need a fractional value here as we are not calculating intra-day values
    static int CalculateJulianDay(int year, int month, double day);
    static Phase GetMoonPhase();
    static Phase GetMoonPhase(int julianDay);
    static Phase GetMoonPhase(int year, int month, double day);
    static std::string GetSegmentName(int segment);

private:
    const double PI = 3.1415926535897932384626433832795;
    const double RAD = (PI/180.0);
    const double SMALL_FLOAT = (1e-12);

    double CalculatePositionOfSun(double julianDay) const;
    double CalculatePositionOfMoon(double julianDay, double sunPosition) const;
    void CalculatePhaseOfMoon(Phase *phase) const;
};

#endif //LUNAR_LUNAR_H
