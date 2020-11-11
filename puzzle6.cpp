#include "catch.hpp"
#include "utils/file-io.h"
#include "utils/md5.h"

//
// Created by User on 18/10/2020.
//

bool startsWith(const char* prefix, const char* text) {
    // TODO: What is the difference between int and size_t?
    size_t prefixLength = strlen(prefix);
    size_t textLength = strlen(text);

    if (prefixLength > textLength) {
        return false;
    }

    return memcmp(prefix, text, prefixLength) == 0;
}


void setLights(bool **lights, bool enabled, int fromX, int fromY, int toX, int toY) {
    for (int x = fromX; x <= toX; x++) {
        for (int y = fromY; y < toY; y++) {
            lights[x][y] = enabled;
        }
    }
}

void toggleLights(bool **lights, int fromX, int fromY, int toX, int toY) {
    for (int x = fromX; x <= toX; x++) {
        for (int y = fromY; y < toY; y++) {
            lights[x][y] = !lights[x][y];
        }
    }
}

// TODO: Maybe make a helper file that reads all lines into an array of strings?
int puzzle6A(char *puzzleInput) {
    bool lights[1000][1000];

    int result;
    char *initial = puzzleInput;
    char *line = puzzleInput;

    do {
        result = sscanf(puzzleInput, "%s", line);
        size_t length = strlen(line);

        if (startsWith("turn", line)) {
            printf("starts with turn\n");
        }
        else if (startsWith("toggle", line)) {
            printf("starts with toggle\n");
        }
        else {
            printf("unexpected line = %s\n", line);
        }

        puzzleInput = puzzleInput + length + 2;
    } while (result > 0);

    free(initial);
//    return niceStringCount;



    return 2;
}

int puzzle6B(char *puzzleInput) {
    return 2;
}

TEST_CASE( "Puzzle 6A", "" ) {
    readFileIntoArray("../puzzles/2015/puzzle6.txt");

    char *puzzleInput = readFile("../puzzles/2015/puzzle6.txt");
//    int niceStrings = puzzle6A(puzzleInput);
//    REQUIRE(niceStrings == 258 );
}

TEST_CASE( "Puzzle 6B", "" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle6.txt");
    REQUIRE( puzzle6B(puzzleInput) == 53 );
}

TEST_CASE( "'Sandeep' should startsWith() 'San'", "" ) {
    REQUIRE(startsWith("San", "Sandeep") == true );
}

TEST_CASE( "'Sandeep' should not startsWith() 'Angus'", "" ) {
    REQUIRE(startsWith("Angus", "Sandeep") == false );
}
