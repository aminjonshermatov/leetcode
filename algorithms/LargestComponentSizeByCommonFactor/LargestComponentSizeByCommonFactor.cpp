#include "bits/stdc++.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
    bool isFirst = true;

    out << '{';
    for (const auto& el : s) {
        if (!isFirst) out << ", ";
        isFirst = false;

        out << el;
    }

    return out << '}';
}

template <typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
    bool isFirst = true;
    out << "{\n";

    for (const auto& [k, v] : m) {
        if (!isFirst) out << ",\n";
        isFirst = false;

        out << '\t' << k << ":\t" << v;
    }

    return out << "\n}\n";
}

class Solution {
public:
    vector<int> parents;
    static constexpr int SIZE = 1e5 + 1;

    void union_(int x, int y) {
        int xP = find_(x),
                yP = find_(y);

        if (xP != yP) parents[yP] = xP;
    }

    int find_(int x) {
        if (parents[x] == -1) return x;
        return parents[x] = find_(parents[x]);
    }

    int largestComponentSize(vector<int>& nums) {
        parents.resize(SIZE, -1);

        for (const auto& x : nums) {
            for (int i = 2; i * i <= x; ++i) {
                if (x % i == 0) {
                    // number before sqrt(x)
                    union_(i, x);

                    // number after sqrt(x)
                    union_(i, x / i);
                }
            }
        }

        unordered_map<int, int> counter;
        int maxCount = 0;

        for (const auto& el : nums) {
            ++counter[find_(el)];
            maxCount = max(maxCount, counter[find_(el)]);
        }

        return maxCount;
    }
};