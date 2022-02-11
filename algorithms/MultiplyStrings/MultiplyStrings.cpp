#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len2 > len1) return multiply(num2, num1);

        vector<vector<char>> mul(len2, vector<char>(len1 + len2, '0'));

        for (int i = len2 - 1; i >= 0; --i) {
            int rem = 0, j;
            for (j = len1 - 1; j >= 0; --j) {
                int temp = (num2[i] - '0') * (num1[j] - '0') + rem;
                rem = temp / 10;
                mul[len2 - i - 1][i + j + 1] = '0' + temp % 10;
            }

            if (rem != 0) mul[len2 - i - 1][i + j + 1] = '0' + rem;
        }

        vector<char> res(len1 + len2, '0');

        int rem = 0;
        for (int i = len1 + len2 - 1; i >= 0; --i) {
            int temp = rem;
            for (int j = len2 - 1; j >= 0; --j) {
                temp += mul[j][i] - '0';
            }
            res[i] = '0' + temp % 10;
            rem = temp / 10;
        }


        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        if (res.empty()) res = {'0'};

        return string(res.begin(), res.end());
    }
};