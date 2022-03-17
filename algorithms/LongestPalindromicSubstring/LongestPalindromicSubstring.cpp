#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        const int n = static_cast<int>(str.size());
        auto s{0};
        auto e{0};

        const function<void(int, int)> longestP = [&](int i, int j) -> void {
            while (i >= 0 and j < n and str[i] == str[j]) {
                if (e - s < j - i) s = i, e = j;

                --i;
                ++j;
            }
        };

        for (int i = 0; i < n; ++i) {
            longestP(i, i);
            longestP(i, i + 1);
        }

        return str.substr(s, e - s + 1);
    }
};