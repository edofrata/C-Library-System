#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library_methods.cpp"


TEST_CASE("Testimng the ToLowerCase method", "[toLowerCase]"){
Utilities util;

    REQUIRE(util.toLowerCase("heLLo") == "hello");
    REQUIRE(util.toLowerCase("TEST") == "test");
    REQUIRE(util.toLowerCase("Title") == "title");
    REQUIRE(util.toLowerCase("crash") == "crash");
}