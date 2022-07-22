#include "bits/stdc++.h"

using namespace std;


class Solution {
    class _counter {
        uint32_t _freq[52] {0u,};

    public:
        uint32_t& operator[](char ch)       { return ch >= 'a' ? _freq[ch - 'a'] : _freq[ch - 'A' + 26]; }
        uint32_t& operator[](size_t idx)    { return _freq[idx]; }
    };

public:
    string minWindow(string s, string t) {
        _counter t_freq;
        for (auto ch : t) ++t_freq[ch];

        _counter w_freq;
        deque<char> dq;
        string res;
        for (auto ch : s) {
            ++w_freq[ch];
            dq.push_back(ch);

            while (!dq.empty() && w_freq[dq.front()] > t_freq[dq.front()]) {
                --w_freq[dq.front()];
                dq.pop_front();
            }

            bool ok = true;
            for (size_t i = 0u; i < 52 && ok; ++i) ok = t_freq[i] <= w_freq[i];
            if (ok && res.empty() || dq.size() < res.size()) res = {dq.begin(), dq.end()};
        }

        return res;
    }
};
