#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int value;
    Node* next;
};

struct QueueLinkedList {
    Node* head = NULL;
    Node* tail = NULL;
};

bool isEmpty(QueueLinkedList &q) { return q.head == NULL; }

void enqueue(QueueLinkedList &q, int x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = NULL;
    if (isEmpty(q)) q.head = q.tail = newNode;
    else {
        q.tail->next = newNode;
        q.tail = newNode;
    }
}

int dequeue(QueueLinkedList &q) {
    if (isEmpty(q)) { cout << "Queue is empty!\n"; return -1; }
    Node* temp = q.head;
    int x = temp->value;
    q.head = q.head->next;
    if (q.head == NULL) q.tail = NULL;
    delete temp;
    return x;
}

int front(QueueLinkedList &q) {
    if (isEmpty(q)) { cout << "Queue is empty!\n"; return -1; }
    return q.head->value;
}

struct QueueArray {
    int a[MAX];
    int head = 0;
    int count = 0;
};

bool isEmpty(QueueArray &q) { return q.count == 0; }

void enqueue(QueueArray &q, int x) {
    if (q.count == MAX) { cout << "Queue is full!\n"; return; }
    q.a[(q.head + q.count) % MAX] = x;
    q.count++;
}

int dequeue(QueueArray &q) {
    if (isEmpty(q)) { cout << "Queue is empty!\n"; return -1; }
    int x = q.a[q.head];
    q.head = (q.head + 1) % MAX;
    q.count--;
    return x;
}

int front(QueueArray &q) {
    if (isEmpty(q)) { cout << "Queue is empty!\n"; return -1; }
    return q.a[q.head];
}

int main() {
    cout << "--- Queue (LinkedList) ---\n";
    QueueLinkedList q1;
    for (int i = 1; i <= 5; i++) enqueue(q1, i * 10);
    cout << "Front: " << front(q1) << "\nDequeue: ";
    while (!isEmpty(q1)) cout << dequeue(q1) << " ";

    cout << "\n\n--- Queue (Array) ---\n";
    QueueArray q2;
    for (int i = 1; i <= 5; i++) enqueue(q2, i * 10);
    cout << "Front: " << front(q2) << "\nDequeue: ";
    while (!isEmpty(q2)) cout << dequeue(q2) << " ";

    cout << "\n";
    return 0;
}
