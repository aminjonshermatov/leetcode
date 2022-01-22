#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> opposite = { {')', '('}, {'}', '{'}, {']', '['} };
        stack<char> st;

        for (const auto ch : s) {
            if (ch == '(' or ch == '{' or ch == '[') st.push(ch);
            else {
                if (not st.empty() and st.top() == opposite[ch]) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};