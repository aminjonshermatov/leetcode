#include "bits/stdc++.h"

using namespace std;

// ax + by = c
struct Graph {
    int a, b, c;

    Graph(const int a_, const int b_, const int c_) : a{a_}, b{b_}, c{c_} { }
    Graph(const Graph& another) : a{another.a}, b{another.b}, c{another.c} { }

    auto operator==(const Graph& rhs) const -> bool { return a == rhs.a and b == rhs.b and c == rhs.c; };
};

namespace std {
    template<>
    struct hash<Graph> {
        size_t operator()(const Graph& p) const noexcept {
            return hash<int>()(p.a) * 31 + hash<int>()(p.b) * 19 + hash<int>()(p.c);
        }
    };
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        unordered_set<Graph> graphs;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // a = y2 - y1
                // b = x1 - x2
                // c = a*x1 + b*y1
                // points[j] = [x2, y2]
                // points[i] = [x1, y1]
                const int a = points[j][1] - points[i][1];
                const int b = points[i][0] - points[j][0];
                const int c = a * points[i][0] + b * points[i][1];

                graphs.insert({a, b, c});
            }
        }


        int res = 1;
        for (const auto &g : graphs) {
            int local = 0;
            for (const auto &p : points) {
                if (g.a * p[0] + g.b * p[1] == g.c) ++local;
            }

            res = max(res, local);
        }
        return res;
    }
};