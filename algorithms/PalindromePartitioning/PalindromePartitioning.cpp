#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;

    vector<vector<string>> partition(string s) {
        backtrack(0, s);

        return res;
    }

    void backtrack(int idx, string& s) {
        if (idx >= s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;

            ++l;
            --r;
        }

        return true;
    }
};