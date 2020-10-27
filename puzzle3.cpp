#include <cstdio>
#include <cstdlib>
#include "catch.hpp"

//
// Created by User on 18/10/2020.
//

struct Point {
    int x;
    int y;
};

struct Node {
    Point* point;
    Node* next;
};

Node *createNode(int x, int y);
Point *createPoint(int x, int y);
void listAdd(Node *head, Node *node);
bool listContains(Node *head, int x, int y);
int listSize(Node *head);
char *readFile(const char *filename);

void processCharacter(Point *position, char c);

int puzzle3B(const char *puzzleInput) {
    Point *santa = createPoint(0, 0);
    Point *robotSanta = createPoint(0, 0);
    Node* head = createNode(0, 0);

    for (int i = 0; i < strlen(puzzleInput); i++) {
        char c = puzzleInput[i];
        Point* activeSanta = i % 2 == 0 ? santa : robotSanta;
        processCharacter(activeSanta, c);

        if (!listContains(head, activeSanta->x, activeSanta->y)) {
            Node* node = createNode(activeSanta->x, activeSanta->y);
            listAdd(head, node);
        }
    }

    return listSize(head);
}

void processCharacter(Point *position, char c) {
    if (c == '>') {
        position->x++;
    }
    else if (c == '<') {
        position->x--;
    }
    else if (c == '^') {
        position->y++;
    }
    else if (c == 'v') {
        position->y--;
    }
    else {
        printf("Unexpected character c = %c", c);
        exit(EXIT_FAILURE);
    }
}

int puzzle3A(const char *puzzleInput) {
    Point *currentPosition = createPoint(0, 0);
    Node* head = createNode(0, 0);

    for (int i = 0; i < strlen(puzzleInput); i++) {
        char c = puzzleInput[i];
        processCharacter(currentPosition, c);

        if (!listContains(head, currentPosition->x, currentPosition->y)) {
            Node* node = createNode(currentPosition->x, currentPosition->y);
            listAdd(head, node);
        }
    }

    return listSize(head);
}

char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    rewind(file);
    char* puzzleInput = (char*)malloc(size);
    fgets(puzzleInput, size, file);
    fclose(file);
    return puzzleInput;
}

int listSize(Node *head) {
    int size = 1;

    while (head->next != nullptr) {
        size++;
        head = head->next;
    }

    return size;
}

bool listContains(Node *head, int x, int y) {
    Node* current = head;

    while (current != nullptr) {
        if (current->point->x == x && current->point->y == y) {
            return true;
        }

        current = current->next;
    }

    return false;
}

Node *createNode(int x, int y) {
    auto* head = (struct Node*)malloc(sizeof(struct Node));
    Point *point = createPoint(x, y);

    head->point = point;
    head->next = nullptr;
    return head;
}

Point *createPoint(int x, int y) {
    auto* point = (struct Point*)malloc(sizeof(struct Point));
    point->x = x;
    point->y = y;

    return point;
}

TEST_CASE( "Puzzle 3A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle3.txt");
    REQUIRE( puzzle3A(puzzleInput) == 2565 );
}

TEST_CASE( "Puzzle 3B", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle3.txt");
    REQUIRE( puzzle3B(puzzleInput) == 2639 );
}

TEST_CASE( ">", "[dunno]" ) {
    REQUIRE( puzzle3A(">") == 2);
}

TEST_CASE( "^v^v^v^v^v", "[dunno]" ) {
    REQUIRE( puzzle3A("^v^v^v^v^v") == 2);
}

TEST_CASE( "listContains() should return true when item is last", "[dunno]" ) {
    Node *head = createNode(0, 0);
    listAdd(head, createNode(0, 1));

    REQUIRE(listContains(head, 0, 0) == true);
    REQUIRE(listContains(head, 0, 1) == true);
}

void listAdd(Node *head, Node *node) {
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = node;
}
