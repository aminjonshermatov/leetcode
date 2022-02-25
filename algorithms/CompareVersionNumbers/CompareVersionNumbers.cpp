#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int compareVersion(string s1, string s2) {
        const function<vector<int>(const string& s)> parseNumbers = [](const string &s) -> vector<int> {
            list<int> nums;
            int cur = 0;

            for (const auto ch : s) {
                if (ch == '.') {
                    nums.push_back(cur);
                    cur = 0;
                }
                else cur = cur * 10 + (ch - '0');
            }

            if (cur != 0) nums.push_back(cur);

            while (not nums.empty()) {
                if (nums.back() != 0) break;
                nums.pop_back();
            }

            return {nums.begin(), nums.end()};
        };

        auto nums1{parseNumbers(s1)};
        auto nums2{parseNumbers(s2)};

        if (nums1 < nums2) return -1;
        else if (nums1 > nums2) return 1;
        return 0;
    }
};