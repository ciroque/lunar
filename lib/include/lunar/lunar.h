#ifndef LUNAR_LUNAR_H
#define LUNAR_LUNAR_H

#include <array>
#include <string>
#include <cmath>

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
    double phase;
    enum Segment segment;
    double visible;
};

struct Position {
    double declination;
    double distance;
    double rightAscension;
};

struct Illumination {
    double angle;
    double phase;
    double visible;
};

class Lunar {
public:
    constexpr static const int EPOCH = 2444238; // [2444238.5] We do not need a fractional value here as we are not calculating intra-day values
    static int CalculateJulianDay(int year, int month, double day);
    static std::string GetSegmentName(int segment);

    static Phase CalculateMoonPhase(int julianDay);
    static Phase CalculateMoonPhase(int year, int month, double day);

private:
    constexpr static const double PI = 3.1415926535897932384626433832795;
    constexpr static const double RAD = (PI/180.0);
    constexpr static const double EARTH_OBLIQUITY = RAD * 23.4397;
    constexpr static const double DISTANCE_FROM_EARTH_TO_SUN = 149598000;

    // v2, based on https://github.com/mourner/suncalc/blob/master/suncalc.js
    static Position CalculateSolarCoordinates(int julianDay);
    static Position CalculateLunarCoordinates(int julianDay);
    static Illumination CalculateIllumination(int julianDay);

    static inline double CalculateEclipticLongitude(double solarMeanAnomaly) {
        auto center = RAD * (1.9148 * sin(solarMeanAnomaly) + 0.02
            * sin(2 * solarMeanAnomaly) + 0.0003 * sin(3 * solarMeanAnomaly));
        auto earthPerihelion = RAD * 102.9372;

        return solarMeanAnomaly + center + earthPerihelion + PI;
    }

    static inline double CalculateDeclination(double l, double b) {
        return std::asin(std::sin(b)
            * std::cos(EARTH_OBLIQUITY) + std::cos(b)
            * std::sin(EARTH_OBLIQUITY) * std::sin(l));
    }

    static inline double CalculateRightAscension(double l, double b) {
        return std::atan2(std::sin(l)
            * std::cos(EARTH_OBLIQUITY) - std::tan(b)
            * std::sin(EARTH_OBLIQUITY), std::cos(l));
    }
};

#endif //LUNAR_LUNAR_H
