#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int half = arr.size() / 2;
        unordered_map<int, int> fr;
        for (auto num : arr) ++fr[num];
        vector<int> freq;
        freq.reserve(fr.size());

        for (auto [_, c] : fr) freq.push_back(c);
        sort(freq.begin(), freq.end());
        auto ans = 0;
        for (auto cur = half, i = (int)freq.size() - 1; cur > 0; ++ans, cur -= freq[i--]) { }

        return ans;
    }
};