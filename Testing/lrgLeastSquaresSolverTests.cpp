#include "catch.hpp"
#include "lrgLinearDataCreator.h"
#include <iostream>
#include <vector>

TEST_CASE( "Instantiate an instance of your new concrete class","[some group identifier]" ) {
	DataCreator d;
	d.GetData();
	REQUIRE( 1 == 1 );
}