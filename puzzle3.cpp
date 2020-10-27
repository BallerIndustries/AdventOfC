#include <cstdio>
#include <cstdlib>
#include "catch.hpp"

//
// Created by User on 18/10/2020.
//

struct Node {
    int x;
    int y;
    Node* next;
};

struct Point {
    int x;
    int y;
};

Node *createNode(int x, int y);
void listAdd(Node *head, Node *node);
bool listContains(Node *head, int x, int y);
Point *createPoint(int x, int y);

int listSize(Node *head);

char *readFile(const char *filename);



int puzzle3A(const char *puzzleInput) {
    Point *currentPosition = createPoint(0, 0);
    Node* head = createNode(0, 0);

    for (int i = 0; i < strlen(puzzleInput); i++) {
        char c = puzzleInput[i];

        if (c == '>') {
            currentPosition->x++;
        }
        else if (c == '<') {
            currentPosition->x--;
        }
        else if (c == '^') {
            currentPosition->y++;
        }
        else if (c == 'v') {
            currentPosition->y--;
        }
        else {
            printf("Unexpected character c = %c", c);
            exit(EXIT_FAILURE);
        }

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
        if (current->x == x && current->y == y) {
            return true;
        }

        current = current->next;
    }

    return false;
}

Node *createNode(int x, int y) {
    Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->x = x;
    head->y = y;
    head->next = nullptr;

    return head;
}

Point *createPoint(int x, int y) {
    Point* point = (struct Point*)malloc(sizeof(struct Point));
    point->x = x;
    point->y = y;

    return point;
}

TEST_CASE( "Puzzle 3A", "[dunno]" ) {
    char *puzzleInput = readFile("../puzzles/2015/puzzle3.txt");
    REQUIRE( puzzle3A(puzzleInput) == 2592 );
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
