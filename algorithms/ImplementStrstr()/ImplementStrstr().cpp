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

class Solution {
    static inline constexpr int64_t P = 31;
    static inline constexpr int64_t MOD = 1e9 + 9;
  public:
    int strStr(string s, string t) {
        const int n(s.size());
        const int m(t.size());

        if (m > n) return -1;

        auto check = [&](int i) -> bool {
          for (int j = 0; j < m; ++j) if (s[i + j] != t[j]) return false;
          return true;
        };

        int64_t t_hash = 0;
        int64_t PP = 1;
        for (int i = 0; i < m; ++i) {
            t_hash = (t_hash * P + t[i] - 'a' + 1 + MOD) % MOD;
            if (i > 0) PP = PP * P % MOD;
        }

        int64_t s_hash = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= m) s_hash = (s_hash - (s[i - m] - 'a' + 1) * PP + MOD) % MOD;
            s_hash = (s_hash * P + s[i] - 'a' + 1 + MOD) % MOD;
            if ((s_hash + MOD) % MOD == (t_hash + MOD) % MOD && check(i - m + 1)) return i - m + 1;
        }
        return -1;
    }
};