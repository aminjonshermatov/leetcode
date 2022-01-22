#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static constexpr int MAX = 1e5;

    bool winnerSquareGame(int n) {
        vector<int> squares;

        for (int i = 1; i * i <= MAX; ++i) {
            squares.push_back(i * i);
        }

        function<int(int)>  lessOrEqual = [&](int k) -> int {
            int lo = 0, hi = squares.size(), ans = 0;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (squares[mid] > k) hi = mid;
                else if (squares[mid] < k) {
                    ans = mid;
                    lo = mid + 1;
                }
                else return mid;
            }

            return ans;
        };

        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            auto idx = lessOrEqual(i);

            while (idx >= 0 and not dp[i]) {
                dp[i] = not dp[i - squares[idx--]];
            }
        }

        return dp[n];
    }
};