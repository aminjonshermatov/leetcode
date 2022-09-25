#include "bits/stdc++.h"

using namespace std;

class MyCircularQueue {
    vector<int> _store;
    int l, r, k, len;

public:
    MyCircularQueue(int k_) : k{k_}, l{0}, r{-1}, len{0} {
        _store.resize(k);
    }

    bool enQueue(int value) {
        if (!isFull()) {
            r = (r + 1) % k;
            _store[r] = value;
            ++len;
            return true;
        } return false;
    }

    bool deQueue() {
        if (!isEmpty()) {
            l = (l + 1) % k;
            --len;
            return true;
        } return false;
    }

    int Front() {
        return isEmpty() ? -1 : _store[l];
    }

    int Rear() {
        return isEmpty() ? -1 : _store[r];
    }

    bool isEmpty() {
        return len == 0;
    }

    bool isFull() {
        return len == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */