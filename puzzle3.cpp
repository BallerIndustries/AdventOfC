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

int puzzle3A() {
    FILE *file = fopen("../puzzles/2015/puzzle3.txt", "r");

    if (file == nullptr) {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    int x = 0;
    int y = 0;
    int c;

    Node* head = createNode(0, 0);
    printf("%p\n", head);

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
        else {
            printf("Unexpected character c = %c", c);
            //exit(EXIT_FAILURE);
        }

        if (!listContains(head, x, y)) {
            //printf("Added to list");
            Node* node = createNode(x, y);
            listAdd(head, node);
        }

        //printf("(%d, %d)\n", x, y);
    } while (c != EOF);

    fclose(file);
    return listSize(head);
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
    REQUIRE( puzzle3A() == 2914 );
}

void listAdd(Node *head, Node *node) {
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = node;
}
