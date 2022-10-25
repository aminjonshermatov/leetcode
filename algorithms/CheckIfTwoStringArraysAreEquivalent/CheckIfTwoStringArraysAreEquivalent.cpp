#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const int N(word1.size());
        const int M(word2.size());

        int i = 0, ii = 0, j = 0, jj = 0;
        while (i < N && j < M) {
            if (word1[i][ii] != word2[j][jj]) return false;
            else {
                if (++ii == word1[i].size()) ++i, ii = 0;
                if (++jj == word2[j].size()) ++j, jj = 0;
            }
        }

        return i == N && ii == 0 && j == M && jj == 0;
    }
};