#include <iostream>
using namespace std;

struct MinHeap {
    int a[100];
    int size = 0;
};

void insert(MinHeap &h, int x) {
    int i = h.size++;
    h.a[i] = x;
    while (i > 0 && h.a[(i - 1) / 2] > h.a[i]) {
        swap(h.a[(i - 1) / 2], h.a[i]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap &h) {
    int root = h.a[0];
    h.a[0] = h.a[--h.size];
    int i = 0;
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2, m = i;
        if (l < h.size && h.a[l] < h.a[m]) m = l;
        if (r < h.size && h.a[r] < h.a[m]) m = r;
        if (m == i) break;
        swap(h.a[i], h.a[m]);
        i = m;
    }
    return root;
}

void print(MinHeap &h) {
    cout << "minHeap : ";
    for (int i = 0; i < h.size; i++) cout << h.a[i] << " ";
    cout << endl;
}

struct MaxHeap {
    int a[100];
    int size = 0;
};

void insert(MaxHeap &h, int x) {
    int i = h.size++;
    h.a[i] = x;
    while (i > 0 && h.a[(i - 1) / 2] < h.a[i]) {
        swap(h.a[(i - 1) / 2], h.a[i]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap &h) {
    int root = h.a[0];
    h.a[0] = h.a[--h.size];
    int i = 0;
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2, m = i;
        if (l < h.size && h.a[l] > h.a[m]) m = l;
        if (r < h.size && h.a[r] > h.a[m]) m = r;
        if (m == i) break;
        swap(h.a[i], h.a[m]);
        i = m;
    }
    return root;
}

void print(MaxHeap &h) {
    cout << "maxHeap : ";
    for (int i = 0; i < h.size; i++) cout << h.a[i] << " ";
    cout << endl;
}

int main() {
    int data[] = {50, 30, 20, 15, 10, 8, 16, 5};

    MinHeap minH;
    for (int x : data) insert(minH, x);
    print(minH);
    cout << "extractMin : " << extractMin(minH) << endl;
    print(minH);

    cout << endl;

    MaxHeap maxH;
    for (int x : data) insert(maxH, x);
    print(maxH);
    cout << "extractMax : " << extractMax(maxH) << endl;
    print(maxH);

    return 0;
}
