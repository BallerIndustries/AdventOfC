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

char **split(const char *pattern, char *text) {
    int matchCount = 0;
    size_t patternLength = strlen(pattern);

    for (int i = 0; i + patternLength < strlen(text); i++) {
        // Move the buffer along
        char *buffer = text + i;

        // Look for a pattern match
        if (memcmp(buffer, pattern, patternLength) == 0) {
            matchCount++;
        }
    }

    char** result = (char **)malloc(matchCount);

    if (matchCount == 0) {
        return result;
    }

    matchCount = 0;
    int lastMatch = 0;

    for (int i = 0; i + patternLength < strlen(text); i++) {
        // Move the buffer along
        char *buffer = text + i;

        if (memcmp(buffer, pattern, patternLength) == 0) {
            int stringLength = i - lastMatch + 1;
            result[matchCount] = (char *)malloc(stringLength);
            memcpy(result[matchCount], text + lastMatch, i - lastMatch);
            result[matchCount][stringLength-1] = 0;
            matchCount++;
            lastMatch = i + patternLength;
        }
    }

    // Copy the last bit
    int stringLength = strlen(text) - lastMatch + 1;
    result[matchCount] = (char *)malloc(stringLength);
    memcpy(result[matchCount], text + lastMatch, strlen(text) - lastMatch);
    result[matchCount][stringLength-1] = 0;

    printf("result[0] = %s\n", result[0]);
    printf("result[1] = %s\n", result[1]);
    printf("result[2] = %s\n", result[2]);
    return result;
}
