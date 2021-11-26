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

class Solution {
public:
    int coinChange(vector<int> coins, int amount) {
        if (amount == 0) return 0;

        sort(coins.begin(), coins.end(), greater<>());
        int res = INT_MAX, local = 0;

        for (int coin : coins) {
            if (amount % coin == 0) {
                res = local + amount / coin;
                amount = 0;
                break;
            }

            while (amount - coin >= 0) {
                amount -= coin;
                res = ++local;
            }
        }

        return amount == 0 && res != INT_MAX ? res : -1;
    }
};

int main() {
    Solution s;
    cout << s.coinChange({186,419,83,408},6249) << '\n';
}