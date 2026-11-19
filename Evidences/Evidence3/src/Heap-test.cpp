#include <iostream>
#include "../include/Heap.h"

using namespace std;

struct Menor {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

struct Mayor {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {

    Heap<int, Menor> minHeap;

    minHeap.push(40);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(5);
    minHeap.push(20);

    cout << "MinHeap:" << endl;

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;

    Heap<int, Mayor> maxHeap;

    maxHeap.push(40);
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(5);
    maxHeap.push(20);

    cout << "MaxHeap:" << endl;

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    return 0;
}