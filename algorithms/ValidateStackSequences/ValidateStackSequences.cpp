#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int lastPoppedIdx = 0;
        for (const auto num : pushed) {
            st.push(num);

            while (not st.empty() and lastPoppedIdx < popped.size() and st.top() == popped[lastPoppedIdx]) {
                ++lastPoppedIdx;
                st.pop();
            }
        }

        while (not st.empty() and lastPoppedIdx < popped.size() and st.top() == popped[lastPoppedIdx]) {
            ++lastPoppedIdx;
            st.pop();
        }

        return lastPoppedIdx == popped.size() and st.empty();
    }
};