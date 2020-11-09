#include "catch.hpp"
#include "utils/file-io.h"
#include "utils/md5.h"

//
// Created by User on 18/10/2020.
//

bool hasAtLeastThreeVowels(const char *line) {
    int vowelCount = 0;

    // CANDICE
    // 0123456
    for (int i = 0; i < strlen(line); i++) {
        char character = line[i];

        if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
            vowelCount = vowelCount + 1;
        }
    }

    return vowelCount >= 3;
}

bool hasRepeatingLetter(const char *line) {
    for (int i = 1; i < strlen(line); i++) {
        char currentLetter = line[i];
        char previousLetter = line[i-1];

        if (currentLetter == previousLetter) {
            return true;
        }
    }

    return false;
}

bool hasAbCdPqOrXy(const char *line) {
    for (int i = 1; i < strlen(line); i++) {
        char currentLetter = line[i];
        char previousLetter = line[i-1];

        if (previousLetter == 'a' && currentLetter == 'b') {
            return true;
        }
        if (previousLetter == 'c' && currentLetter == 'd') {
            return true;
        }
        if (previousLetter == 'p' && currentLetter == 'q') {
            return true;
        }
        if (previousLetter == 'x' && currentLetter == 'y') {
            return true;
        }
    }

    return false;
}

int puzzle5A(char *puzzleInput) {
    int result;
    int niceStringCount = 0;
    char *initial = puzzleInput;
    char *line = puzzleInput;

    do {
        result = sscanf(puzzleInput, "%s\r\n", line);
        size_t length = strlen(line);

        if (hasAtLeastThreeVowels(line) && hasRepeatingLetter(line) && !hasAbCdPqOrXy(line)) {
            niceStringCount = niceStringCount + 1;
        }

        puzzleInput = puzzleInput + length + 2;
    } while (result > 0);

    free(initial);
    return niceStringCount;
}

int puzzle5B(const char *puzzleInput) {
    return 1;
}

TEST_CASE( "Puzzle 5A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    int niceStrings = puzzle5A(puzzleInput);
    REQUIRE(niceStrings == 258 );
}

TEST_CASE( "Puzzle 5B", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    REQUIRE( puzzle5B(puzzleInput) == 2639 );
}
