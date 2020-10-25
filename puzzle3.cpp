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

Node *createNode(int x, int y);
void listAdd(Node *head, Node *node);
bool listContains(Node *head, int x, int y);

int listSize(Node *head);

char *readFile(const char *filename);

int puzzle3A(const char *puzzleInput) {
    //char *puzzleInput = readFile("../puzzles/2015/puzzle3.txt");

    int x = 0;
    int y = 0;
    char c;

    Node* head = createNode(0, 0);

    for (int i = 0; i < strlen(puzzleInput); i++) {
        c = puzzleInput[i];

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
        else {
            printf("Unexpected character c = %c", c);
            exit(EXIT_FAILURE);
        }

        if (!listContains(head, x, y)) {
            Node* node = createNode(x, y);
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

    while (current->next != nullptr) {
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

TEST_CASE( "Puzzle 3A", "[dunno]" ) {
    // 2914 too high
    char *puzzleInput = readFile("../puzzles/2015/puzzle3.txt");
    REQUIRE( puzzle3A(puzzleInput) == 2914 );
}

TEST_CASE( ">", "[dunno]" ) {
    REQUIRE( puzzle3A(">") == 2);
}

TEST_CASE( "^v^v^v^v^v", "[dunno]" ) {
    REQUIRE( puzzle3A("^v^v^v^v^v") == 2);
}

void listAdd(Node *head, Node *node) {
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = node;
}
