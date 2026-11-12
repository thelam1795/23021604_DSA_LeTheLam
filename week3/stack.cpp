#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int value;
    Node* next;
};

struct StackLinkedList {
    Node* topNode = NULL;
};

bool isEmpty(StackLinkedList &s) { return s.topNode == NULL; }

void push(StackLinkedList &s, int x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = s.topNode;
    s.topNode = newNode;
}

int pop(StackLinkedList &s) {
    if (isEmpty(s)) { cout << "Stack is empty!\n"; return -1; }
    Node* temp = s.topNode;
    int x = temp->value;
    s.topNode = s.topNode->next;
    delete temp;
    return x;
}

int top(StackLinkedList &s) {
    if (isEmpty(s)) { cout << "Stack is empty!\n"; return -1; }
    return s.topNode->value;
}

struct StackArray {
    int a[MAX];
    int topIndex = -1;
};

bool isEmpty(StackArray &s) { return s.topIndex == -1; }

void push(StackArray &s, int x) {
    if (s.topIndex == MAX - 1) { cout << "Stack is full!\n"; return; }
    s.a[++s.topIndex] = x;
}

int pop(StackArray &s) {
    if (isEmpty(s)) { cout << "Stack is empty!\n"; return -1; }
    return s.a[s.topIndex--];
}

int top(StackArray &s) {
    if (isEmpty(s)) { cout << "Stack is empty!\n"; return -1; }
    return s.a[s.topIndex];
}

int main() {
    cout << "--- Stack (LinkedList) ---\n";
    StackLinkedList s1;
    for (int i = 1; i <= 5; i++) push(s1, i * 10);
    cout << "Top: " << top(s1) << "\nPop: ";
    while (!isEmpty(s1)) cout << pop(s1) << " ";

    cout << "\n\n--- Stack (Array) ---\n";
    StackArray s2;
    for (int i = 1; i <= 5; i++) push(s2, i * 10);
    cout << "Top: " << top(s2) << "\nPop: ";
    while (!isEmpty(s2)) cout << pop(s2) << " ";

    cout << "\n";
    return 0;
}