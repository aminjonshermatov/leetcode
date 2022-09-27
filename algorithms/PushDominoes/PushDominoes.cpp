#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string pushDominoes(string s) {
        const int N(s.size());
        vector<int> L(N, 0), R(N, 0);

        L[N - 1] = s[N - 1] == 'L' ? 1 : 0;
        for (int i = N - 2; i >= 0; --i) {
            if (s[i] == 'L') L[i] = 1;
            else if (s[i] == '.' && L[i + 1] > 0) L[i] = L[i + 1] + 1;
        }

        R[0] = s[0] == 'R' ? 1 : 0;
        for (int i = 1; i < N; ++i) {
            if (s[i] == 'R') R[i] = 1;
            else if (s[i] == '.' && R[i - 1] > 0) R[i] = R[i - 1] + 1;
        }

        auto res = s;
        for (int i = 0; i < N; ++i)
            if (res[i] == '.' && L[i] != R[i]) {
                if (L[i] > 0 && R[i] > 0) res[i] = L[i] < R[i] ? 'L' : 'R';
                else if (L[i] > 0) res[i] = 'L';
                else if (R[i] > 0) res[i] = 'R';
            }

        return res;
    }
};
/*
  RR.L

l:0010
r:0010

  .L.R...LR..L..
l:10003210021000
r:00001230012000
A:LL.RR.LLRRLL..
  LL.RR.LLRRLL..
*/