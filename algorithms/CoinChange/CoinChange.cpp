#include "bits/stdc++.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << '[';

    bool isFirst = true;

    for (const auto& el : v) {
        if (!isFirst) out << ", ";
        isFirst = false;
        out << el;
    }

    return out << ']';
}

// DFS + cache
class Solution {
public:
    unordered_map<int, int> cache;

    int coinChange(vector<int> coins, int amount) {
        int minCoins = dfs(coins, amount, amount);

        return minCoins <= amount + 1 ? minCoins - 1 : -1;
    }

    int dfs(vector<int>& coins, int tempAmount, int amount) {
        if (tempAmount < 0) return -1;
        if (tempAmount == 0) return 1;

        if (cache.find(tempAmount) != cache.end()) return cache[tempAmount];

        int temp = amount + 1;

        for (const int& coin : coins) {
            auto cur = dfs(coins, tempAmount - coin, amount);

            if (cur > 0) {
                temp = min(temp, cur);
                cache[tempAmount - coin] = cur;
            }
        }

        return temp + 1;
    }
};

// DP
class Solution {
    int dp[10001];

public:
    int coinChange(vector<int>& coins, int amount) {
        for (int a = 1; a <= amount; ++a) dp[a] = amount + 1;
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (const auto coin : coins) {
                if (a >= coin) dp[a] = min(dp[a], 1 + dp[a - coin]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};