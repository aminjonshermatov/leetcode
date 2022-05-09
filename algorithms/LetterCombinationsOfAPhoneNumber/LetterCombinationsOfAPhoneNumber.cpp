#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    unordered_map<char, vector<string>> keys = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}},
    };

    // O(4^n) - TC, O(1) - SC (exclusive result array and hashMap)
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        if (digits.size() == 1) return keys.at(digits.front());

        vector<string> res;
        for (const auto &str : letterCombinations({next(digits.begin()), digits.end()})) {
            for (const auto &d : keys.at(digits.front())) {
                res.push_back(d + str);
            }
        }

        return res;
    };
};