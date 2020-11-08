#include "catch.hpp"
#include "utils/file-io.h"
#include "utils/md5.h"

//
// Created by User on 18/10/2020.
//

int puzzle5A(const char *puzzleInput) {
    char *line;
    int result;
//    size_t length;

    result = sscanf(puzzleInput, "%s", line);
    size_t length = strlen(line);

    printf("length = %i\n", length);
    printf("line = %s\n", line);
    printf("result = %i\n", result);

    //const char *octopus = (puzzleInput + length);
    puzzleInput = puzzleInput + length + 2;

    result = sscanf(puzzleInput, "%s\n", line);
    length = strlen(line);
    printf("length = %i\n", length);
    printf("line = %s\n", line);
    printf("result = %i\n", result);


    return 1;
}

int puzzle5B(const char *puzzleInput) {
    return 1;
}

TEST_CASE( "Puzzle 5A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    REQUIRE( puzzle5A(puzzleInput) == 2565 );
}

TEST_CASE( "Puzzle 5B", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    REQUIRE( puzzle5B(puzzleInput) == 2639 );
}
