#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string interpret(string command) {
        list<char> str;

        const int n = static_cast<int>(command.size());
        for (int i = 0; i < n; ++i) {
            if (command[i] == '(') {
                if (i + 1 < n and command[i + 1] == ')') {
                    str.push_back('o');
                    ++i;
                } else if (i + 3 < n and command[i + 3] == ')') {
                    str.push_back('a');
                    str.push_back('l');
                    i += 3;
                }
            } else str.push_back(command[i]);
        }

        return {str.begin(), str.end()};
    }
};