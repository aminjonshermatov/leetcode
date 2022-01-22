#include "bits/stdc++.h"

using namespace std;

class MyQueue {
private:
    stack<int> st1, st2;
    int front;

public:
    MyQueue() {

    }

    void push(int x) {
        if (st1.empty()) front = x;
        st1.push(x);
    }

    int pop() {
        while (st1.size() > 1) {
            auto t{st1.top()};
            st1.pop();

            st2.push(t);
        }

        auto t{st1.top()};
        st1.pop();

        if (not st2.empty()) front = st2.top();

        while (not st2.empty()) {
            auto t{st2.top()};
            st2.pop();

            st1.push(t);
        }

        return t;
    }

    int peek() {
        assert(not st1.empty());

        return front;
    }

    bool empty() {
        return st1.empty() and st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */