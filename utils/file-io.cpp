//
// Created by User on 27/10/2020.
//

#include <cstring>
#include "file-io.h"

char **readFileIntoArray(const char *filename) {
    FILE *file = fopen(filename, "r");

    // Exit if the file cannot be opened
    if (file == nullptr) {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int lineCount = 0;

    // Count the number of lines in the text file
    while (fgets(buffer, sizeof(buffer), file) != nullptr) {
        lineCount++;
    }

    // Point the stream back to the start
    rewind(file);

    // Allocate an array for the number of lines in the text file
    char** lines = (char **)malloc(lineCount * sizeof(char**));
    int index = 0;

    // Copy each line into the lines array
    while (fgets(buffer, sizeof(buffer), file) != nullptr) {
        lines[index] = (char *)malloc(strlen(buffer) * sizeof(char*));
        strcpy(lines[index], buffer);
        index++;
    }

    // Debug step, output all the lines from the array
    for (int i = 0; i < lineCount; i++) {
        printf("%s", lines[i]);
    }

    // return the array of strings
    return lines;
}

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
