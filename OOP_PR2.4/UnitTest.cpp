#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Matrix.hpp"
#include "Matrix.cpp"

TEST_CASE( "Arguments initialized") {
    Matrix testing1;
    testing1.set_col(5);
    REQUIRE( testing1.get_col() == 5);
}
