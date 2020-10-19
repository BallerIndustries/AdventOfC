#include <cstdio>
#include <cstdlib>

//
// Created by User on 18/10/2020.
//
int min(int a, int b);
int wrapperPaper(int length, int width, int height);

void puzzle2() {
    FILE *file = fopen("../puzzles/2015/puzzle2.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    int length;
    int width;
    int height;
    int total = 0;

    while (fscanf(file, "%dx%dx%d", &length, &width, &height) != EOF) {
        total += wrapperPaper(length, width, height);
    }

    printf("total = %d", total);
}

int wrapperPaper(int length, int width, int height) {
    int area = 2 * length * width + 2 * width * height + 2 * height * length;

    int sideA = length * width;
    int sideB = width * height;
    int sideC = length * height;
    int smallestSide = min(min(sideA, sideB), min(sideA, sideC));

    return area + smallestSide;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}