#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../lib/include/lunar/lunar.h"

TEST_CASE( "Julian dates are calculated correctly", "[julian]" ) {
    REQUIRE( Lunar::CalculateJulianDay(-4713, 11, 24) + Lunar::EPOCH == 0 );
    REQUIRE( Lunar::CalculateJulianDay(0, 12, 25) + Lunar::EPOCH == 1721419 );
    REQUIRE( Lunar::CalculateJulianDay(2001, 01, 1) + Lunar::EPOCH == 2451911 );
    REQUIRE( Lunar::CalculateJulianDay(1968, 05, 31) + Lunar::EPOCH == 2440008 );
    REQUIRE( Lunar::CalculateJulianDay(2021, 10, 02) + Lunar::EPOCH == 2459490 );
}

TEST_CASE( "Returns the correct segment name for the phase" ) {
    REQUIRE( Lunar::GetSegmentName(Segment::New) == "New" );
    REQUIRE( Lunar::GetSegmentName(Segment::WaxingCrescent) == "Waxing Crescent" );
    REQUIRE( Lunar::GetSegmentName(Segment::FirstQuarter) == "First Quarter" );
    REQUIRE( Lunar::GetSegmentName(Segment::WaxingGibbous) == "Waxing Gibbous" );
    REQUIRE( Lunar::GetSegmentName(Segment::Full) == "Full" );
    REQUIRE( Lunar::GetSegmentName(Segment::WaningGibbous) == "Waning Gibbous" );
    REQUIRE( Lunar::GetSegmentName(Segment::ThirdQuarter) == "Third Quarter" );
    REQUIRE( Lunar::GetSegmentName(Segment::WaningCrescent) == "Waning Crescent" );
}


