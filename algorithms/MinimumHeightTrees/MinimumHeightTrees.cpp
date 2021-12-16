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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        unordered_map<int, unordered_set<int>> adj;
        unordered_map<int, int> degree;

        for (const auto& p : edges) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
            degree[p[0]]++;
            degree[p[1]]++;
        }

        vector<int> res;
        deque<int> d;

        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) d.push_back(i);
        }

        int count = n;
        while(count > 2) {
            int size = d.size();
            count -= size;

            while (size-- > 0) {
                int node = d.front();
                d.pop_front();

                for (const auto& el : adj[node]) {
                    degree[el]--;
                    adj[el].erase(node);

                    if (degree[el] == 1) d.push_back(el);
                }
            }
        }

        while (!d.empty()) {
            res.push_back(d.front());
            d.pop_front();
        }

        return res;
    }
};