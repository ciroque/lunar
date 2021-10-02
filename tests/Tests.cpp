#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../lib/include/lunar/lunar.h"

TEST_CASE( "Julian dates are calculated correctly", "[julian]" ) {
    REQUIRE( Lunar::CalculateJulianDay(-4713, 11, 24) == 0 );
    REQUIRE( Lunar::CalculateJulianDay(0, 12, 25) == 1721419 );
    REQUIRE( Lunar::CalculateJulianDay(2001, 01, 1) == 2451911 );
    REQUIRE( Lunar::CalculateJulianDay(1968, 05, 31) == 2440008 );
    REQUIRE( Lunar::CalculateJulianDay(2021, 10, 02) == 2459490 );
}
