/*
 * adapted from: http://www.voidware.com/phase.c
 * CalculateJulianDate from: https://www.programmingassignmenthelper.com/convert-a-date-to-the-julian-day-number-in-c/
 */
#include "lunar.h"

#include <math.h>

#include <ctime>

Phase Lunar::GetMoonPhase() {
    const int BASE_YEAR = 1900;
    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);
    return GetMoonPhase(local_time->tm_year + BASE_YEAR, local_time->tm_mon + 1, local_time->tm_mday);
}

Phase Lunar::GetMoonPhase(unsigned int year, unsigned int month, double day) {
    auto lunar = new Lunar();
    auto phase = Phase{};

    phase.julianDay = lunar->CalculateJulianDay(year, month, day);
    phase.sunPosition = lunar->CalculatePositionOfSun(phase.julianDay);
    phase.moonPosition = lunar->CalculatePositionOfMoon(phase.julianDay, phase.sunPosition);

    lunar->CalculatePhaseOfMoon(&phase);

    delete lunar;

    return phase;
}

double Lunar::CalculateJulianDay(unsigned int year, unsigned int month, double day) {
    int a, m, y, leap_days;
    a = ((14 - month) / 12);
    m = (month - 3) + (12 * a);
    y = year + 4800 - a;
    leap_days = (y / 4) - (y / 100) + (y / 400);
    return (day + (((153 * m) + 2) / 5) + (365 * y) + leap_days - 32045) - 2444238.5;
}

double Lunar::CalculatePositionOfSun(double j) {
    double n, x, e, l, dl, v;
    double m2;
    int i;

    n = 360 / 365.2422 * j;
    i = n / 360;
    n = n - i * 360.0;
    x = n - 3.762863;
    if(x < 0) x += 360;
    x *= RAD;
    e = x;
    do {
        dl = e - .016718 * sin(e) - x;
        e = e - dl / (1-.016718 * cos(e));
    } while (fabs(dl) >= SMALL_FLOAT);
    v = 360 / PI * atan(1.01686011182 * tan(e / 2));
    l = v + 282.596403;
    i = l / 360;
    l = l - i * 360.0;
    return l;
}

double Lunar::CalculatePositionOfMoon(double julianDay, double sunPosition) {
    double ms,l,mm,n,ev,sms,z,x,lm,bm,ae,ec;
    double d;
    double ds, as, dm;
    int i;

    /* ls = sun_position(j) */
    ms = 0.985647332099 * julianDay - 3.762863;
    if (ms < 0) ms += 360.0;
    l = 13.176396 * julianDay + 64.975464;
    i = l / 360;
    l = l - i * 360.0;
    if (l < 0) l += 360.0;
    mm = l - 0.1114041 * julianDay - 349.383063;
    i = mm / 360;
    mm -= i * 360.0;
    n = 151.950429 - 0.0529539 * julianDay;
    i = n / 360;
    n -= i * 360.0;
    ev = 1.2739 * sin((2 * (l - sunPosition) - mm) * RAD);
    sms = sin(ms * RAD);
    ae = 0.1858 * sms;
    mm += ev - ae - 0.37 * sms;
    ec = 6.2886 * sin(mm * RAD);
    l += ev + ec - ae + 0.214 * sin(2 * mm * RAD);
    l= 0.6583 * sin(2 * (l - sunPosition) * RAD) + l;
    return l;
}

void Lunar::CalculatePhaseOfMoon(Phase *phase) {
    double t = phase->moonPosition - phase->sunPosition;
    if (t < 0) t += 360;

    phase->visible = (1.0 - cos((phase->moonPosition - phase->sunPosition) * RAD)) / 2;
    phase->segment = (Segment)((int)((t + 22.5) / 45) & 0x7);
}

const std::string Lunar::GetSegmentName(int segment) {
    const std::array<std::string, 8> segmentNames = {
            "New",
            "Waning Crescent",
            "Third Quarter",
            "Waning Gibbous",
            "Full",
            "Waxing Gibbous",
            "First Quarter",
            "Waxing Crescent"};

    return segmentNames.at(segment);
}
