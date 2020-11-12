//
// Created by User on 11/11/2020.
//

#include "catch.hpp"
#include "utils/file-io.h"

TEST_CASE( "should be able to split a string into three pieces", "" ) {
    int resultSize = 0;
    char **result = split(" ", "good morning sandeep", &resultSize);
    REQUIRE(resultSize == 3);
    REQUIRE(strcmp(result[0], "good") == 0);
    REQUIRE(strcmp(result[1], "morning") == 0);
    REQUIRE(strcmp(result[2], "sandeep") == 0);
}

TEST_CASE( "should be able to split a hypenated string into three pieces", "" ) {
    int resultSize = 0;
    char **result = split("--", "good--morning--sandeep", &resultSize);
    REQUIRE(resultSize == 3);
    REQUIRE(strcmp(result[0], "good") == 0);
    REQUIRE(strcmp(result[1], "morning") == 0);
    REQUIRE(strcmp(result[2], "sandeep") == 0);
}

TEST_CASE( "should get back an one element array when there are no matches", "" ) {
    int resultSize = 0;
    char **result = split("--", "goodmorningsandeep", &resultSize);
    REQUIRE(resultSize == 1);
    REQUIRE(strcmp(result[0], "goodmorningsandeep") == 0);
}

TEST_CASE( "can I do a zero malloc?", "" ) {
    malloc(0);
}