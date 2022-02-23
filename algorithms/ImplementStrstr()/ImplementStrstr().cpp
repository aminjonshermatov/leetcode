#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        const int n = static_cast<int>(haystack.size());
        const int m = static_cast<int>(needle.size());

        if (n < m) return -1;
        else if (n == m) return haystack == needle ? 0 : -1;

        for (int i = 0; i < n - m + 1; ++i) {
            if (haystack[i] == needle[0]) {
                int j = i + 1, k = 1;
                bool isOk = true;

                while (j < n and k < m and isOk) {
                    if (haystack[j] != needle[k]) isOk = false;
                    ++j, ++k;
                }

                if (isOk) return i;
            }
        }

        return -1;
    }
};