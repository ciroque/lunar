/*
 * adapted from: http://www.voidware.com/phase.c
 */


#include "lunar.h"

#include <iostream>

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
