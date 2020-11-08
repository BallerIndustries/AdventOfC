//
// Created by User on 27/10/2020.
//

#include "file-io.h"

char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == nullptr) {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    char* puzzleInput = (char*)malloc(size);
    int result = fread(puzzleInput, 1, size, file);

    if (result != size) {
        printf("Failed to read file\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return puzzleInput;
}
