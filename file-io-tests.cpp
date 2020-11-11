//
// Created by User on 11/11/2020.
//

#include "catch.hpp"
#include "utils/file-io.h"

TEST_CASE( "should be able to split a string into three pieces", "" ) {
    int matchCount = 0;
    char **result = split(" ", "good morning sandeep", &matchCount);
    REQUIRE(matchCount == 2);
    REQUIRE(strcmp(result[0], "good") == 0);
    REQUIRE(strcmp(result[1], "morning") == 0);
    REQUIRE(strcmp(result[2], "sandeep") == 0);
}

TEST_CASE( "should be able to split a hypenated string into three pieces", "" ) {
    int matchCount = 0;
    char **result = split("--", "good--morning--sandeep", &matchCount);
    REQUIRE(matchCount == 2);
    REQUIRE(strcmp(result[0], "good") == 0);
    REQUIRE(strcmp(result[1], "morning") == 0);
    REQUIRE(strcmp(result[2], "sandeep") == 0);
}

TEST_CASE( "can I do a zero malloc?", "" ) {
    malloc(0);
}