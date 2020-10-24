#include <cstdio>
#include <cstdlib>
#include "catch.hpp"

//
// Created by User on 18/10/2020.
//
int min(int a, int b);
int wrapperPaper(int length, int width, int height);
int ribbonLength(long length, long width, long height);

int puzzle2A() {
    FILE *file = fopen("../puzzles/2015/puzzle2.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    long length;
    long width;
    long height;
    long total = 0;

    while (fscanf(file, "%ldx%ldx%ld", &length, &width, &height) != EOF) {
        total += wrapperPaper(length, width, height);
    }

    return total;
}

long puzzle2B() {
    FILE *file = fopen("../puzzles/2015/puzzle2.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    long length;
    long width;
    long height;
    long total = 0;

    while (fscanf(file, "%ldx%ldx%ld", &length, &width, &height) != EOF) {
        total += ribbonLength(length, width, height);
    }

    return total;
}

int wrapperPaper(int length, int width, int height) {
    int area = 2 * length * width + 2 * width * height + 2 * height * length;

    int sideA = length * width;
    int sideB = width * height;
    int sideC = length * height;
    int smallestSide = min(min(sideA, sideB), min(sideA, sideC));

    return area + smallestSide;
}

int ribbonLength(long length, long width, long height) {
    long volume = length * width * height;

    if (length > width && length > height) {
        // length is the largest
        return width * 2 + height * 2 + volume;
    }
    else if (width > length && width > height) {
        // width is the largest
        return length * 2 + height * 2 + volume;
    }
    else {
        // height is the largest
        return width * 2 + length * 2 + volume;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

TEST_CASE( "Puzzle 2A", "[dunno]" ) {
    REQUIRE( puzzle2A() == 1606483 );
}

TEST_CASE( "Puzzle 2B", "[dunno]" ) {
    REQUIRE( puzzle2B() == 3842356 );
}
