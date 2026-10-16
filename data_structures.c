#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ARRAY
typedef struct {
    int data[100];
    int n;
} Array;

int get_element(Array *arr, int i) {
    return arr->data[i];
}

Array delete_element(Array *arr, int i) {
    for (int j = i; j <= (arr->n) - 2; j++) {
        arr->data[j] = arr->data[j + 1];
    }
    arr->n--;
    return *arr;
}

Array insert_element(Array *arr, int i, int x) {
    for (int j = (arr->n) - 1; j >= i; j--) {
        arr->data[j + 1] = arr->data[j];
    }
    arr->data[i] = x;
    arr->n++;
    return *arr;
}

// Singly Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_singly(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

// DOUBLY LINKED LIST
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void insert_doubly(DNode** head, int value) {
    DNode* new_node = (DNode*)malloc(sizeof(DNode));
    new_node->data = value;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) (*head)->prev = new_node;
    *head = new_node;
}

// CIRCULAR LINKED LIST
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

void insert_circular(CNode** head, int value) {
    CNode* new_node = (CNode*)malloc(sizeof(CNode));
    new_node->data = value;
    if (*head == NULL) {
        new_node->next = new_node;
        *head = new_node;
    } else {
        CNode* temp = *head;
        while (temp->next != *head) { temp = temp->next; }
        new_node->next = *head;
        temp->next = new_node;
        *head = new_node;
    }
}

// STACK
typedef struct {
    int data[100];
    int n;
} Stack;

void init_stack(Stack* s) {
    s->n = 0;
}

Stack push(Stack* s, int x) {
    if (s->n < 100) {
        s->data[s->n] = x;
        s->n++;
    }
    return *s;
}

int pop(Stack* s) {
    if (s->n > 0) {
        int x = s->data[s->n - 1];
        s->n--;
        return x;
    }
    return -1;
}

int peek(Stack* s) {
    if (s->n > 0) {
        return s->data[s->n - 1];
    }
    return -1;
}

// QUEUE
typedef struct {
    int data[100];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

Queue enqueue(Queue* q, int x) {
    if (q->rear < 100) {
        q->data[q->rear] = x;
        q->rear++;
    }
    return *q;
}

int dequeue(Queue* q) {
    if (q->front < q->rear) {
        int x = q->data[q->front];
        q->front++;
        return x;
    }
    return -1;
}

int front(Queue* q) {
    if (q->front < q->rear) {
        return q->data[q->front];
    }
    return -1;
}

// Simple Hash Function
int hash(const char* key, int size) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) sum += key[i];
    return sum % size;
}