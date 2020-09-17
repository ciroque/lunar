/*
 * adapted from: http://www.voidware.com/phase.c
 * CalculateJulianDate from: https://www.programmingassignmenthelper.com/convert-a-date-to-the-julian-day-number-in-c/
 */

#include <math.h>

#include "lunar.h"

std::list<Phase> Lunar::GetMoonPhases() {
    return std::list<Phase>();
}

double Lunar::CalculateJulianDay(int year, int month, double day) {
    int a, m, y, leap_days;
    a = ((14 - month) / 12);
    m = (month - 3) + (12 * a);
    y = year + 4800 - a;
    leap_days = (y / 4) - (y / 100) + (y / 400);
    return day + (((153 * m) + 2) / 5) + (365 * y) + leap_days - 32045;
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
