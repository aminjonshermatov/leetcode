#include "bits/stdc++.h"

using namespace std;

class MinStack {
    stack<int> st, minSt;
    int minEl;

public:
    MinStack() : minEl{INT_MAX} { };

    void push(int val) {
        st.push(val);
        minEl = min(minEl, val);
        minSt.push(minEl);
    }

    void pop() {
        st.pop();
        minSt.pop();

        if (not minSt.empty()) minEl = minSt.top();
        else minEl = INT_MAX;
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */