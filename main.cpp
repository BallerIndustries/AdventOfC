#include <iostream>
#include "string.h"

int main() {
    int bufferLength = 255;
    char buffer[bufferLength];
    int currentFloor = 0;
    int currentPosition = 0;
    bool beenToBasementBefore = false;

    FILE *file = fopen("../puzzles/2015/puzzle1.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, bufferLength, file)) {
        size_t length = strlen(buffer);

        for (int i = 0; i < length; i++) {
            currentPosition++;

            if (buffer[i] == '(') {
                currentFloor++;
            }
            else if (buffer[i] == ')') {
                currentFloor--;
            }

            if (!beenToBasementBefore && currentFloor == -1) {
                beenToBasementBefore = true;
                printf("Reached the basement at position = %d\n", currentPosition);
            }
        }
    }

    fclose(file);
    printf("currentFloor = %d", currentFloor);
    return 0;
}

