#include "catch.hpp"
#include "utils/file-io.h"
#include "utils/md5.h"

//
// Created by User on 18/10/2020.
//

bool appearsAfterIndex(const char* line, int index, char previous, char current) {
    for (int i = index + 2; i < strlen(line); i++) {
        char newPrevious = line[i-1];
        char newCurrent = line[i];

        if (newPrevious == previous && newCurrent == current) {
            return true;
        }
    }

    return false;
}

bool hasTwoRepeatingLetters(const char *line) {
    for (int i = 1; i < strlen(line); i++) {
        char previous = line[i-1];
        char current = line[i];

        if (appearsAfterIndex(line, i, previous, current)) {
            return true;
        }
    }

    return false;
}

bool hasXYXPattern(const char *line) {
    for (int i = 2; i < strlen(line); i++) {
        char first = line[i-2];
        char third = line[i];

        if (first == third) {
            return true;
        }
    }

    return false;
}

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

int puzzle5B(char *puzzleInput) {
    int result;
    int niceStringCount = 0;
    char *initial = puzzleInput;
    char *line = puzzleInput;

    do {
        result = sscanf(puzzleInput, "%s\r\n", line);
        size_t length = strlen(line);

        if (hasTwoRepeatingLetters(line) && hasXYXPattern(line)) {
            niceStringCount = niceStringCount + 1;
        }

        puzzleInput = puzzleInput + length + 2;
    } while (result > 0);

    free(initial);
    return niceStringCount;
}

TEST_CASE( "Puzzle 5A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    int niceStrings = puzzle5A(puzzleInput);
    REQUIRE(niceStrings == 258 );
}

TEST_CASE( "Puzzle 5B", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle5.txt");
    REQUIRE( puzzle5B(puzzleInput) == 53 );
}
