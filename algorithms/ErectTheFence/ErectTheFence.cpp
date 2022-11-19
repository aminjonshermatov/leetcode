class Solution {
    // x_1*(y_2 - y_3) + x_2*(y_3 - y_1) + x_3 * (y_1 - y_2)
    static inline bool cw(const vector<int> &a, vector<int> &b, vector<int> &c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) <= 0;
    }

    static inline bool ccw(const vector<int> &a, vector<int> &b, vector<int> &c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) >= 0;
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        const int N(trees.size());
        if (N == 1) return trees;

        sort(trees.begin(), trees.end(), [](auto &l, auto &r) { return l[0] < r[0] || (l[0] == r[0] && l[1] < r[1]); });
        auto p1 = trees.front(), p2 = trees.back();
        vector<vector<int>> up, bottom;
        up.push_back(p1);
        bottom.push_back(p1);
        for (int i = 0; i < N; ++i) {
            if (i + 1 == N || cw(p1, trees[i], p2)) {
                while (up.size() > 1 && !cw(up[up.size() - 2], up[up.size() - 1], trees[i])) up.pop_back();
                up.push_back(trees[i]);
            }
            if (i + 1 == N || ccw(p1, trees[i], p2)) {
                while (bottom.size() > 1 && !ccw(bottom[bottom.size() - 2], bottom[bottom.size() - 1], trees[i])) bottom.pop_back();
                bottom.push_back(trees[i]);
            }
        }

        set<vector<int>> ss;
        for (auto &a : up) ss.emplace(a);
        for (auto &a : bottom) ss.emplace(a);

        return {ss.begin(), ss.end()};
    }
};