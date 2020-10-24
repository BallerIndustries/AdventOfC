#include <cstdio>
#include <cstdlib>
#include "catch.hpp"

//
// Created by User on 18/10/2020.
//
int puzzle3A() {
    FILE *file = fopen("../puzzles/2015/puzzle3.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    int x = 0;
    int y = 0;
    char c;

    do {
        c = fgetc(file);

        if (c == '>') {
            x++;
        }
        else if (c == '<') {
            x--;
        }
        else if (c == '^') {
            y++;
        }
        else if (c == 'v') {
            y--;
        }

        //printf("(%d, %d)\n", x, y);
    } while (c != EOF);

    fclose(file);
    return 12;
}

TEST_CASE( "Puzzle 3A", "[dunno]" ) {
    REQUIRE( puzzle3A() == 1606483 );
}
