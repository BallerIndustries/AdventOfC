#include "catch.hpp"
#include "utils/file-io.h"

//
// Created by User on 18/10/2020.
//

int puzzle4A(const char *puzzleInput) {
    return 1;
}

int puzzle4B(const char *puzzleInput) {
    return 1;
}

TEST_CASE( "Puzzle 4A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle4.txt");
    REQUIRE( puzzle4A(puzzleInput) == 2565 );
}

TEST_CASE( "Puzzle 4B", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle4.txt");
    REQUIRE( puzzle4B(puzzleInput) == 2639 );
}
