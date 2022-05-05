#include "bits/stdc++.h"

using namespace std;

class MyStack {
    queue<int> q;

public:
    MyStack() = default;

    void push(int x) {
        int sz = static_cast<int>(q.size());
        q.push(x);
        while (sz--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        auto t{q.front()};
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */