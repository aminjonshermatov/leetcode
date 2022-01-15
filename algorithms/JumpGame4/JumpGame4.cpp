#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> sameEl;

        for (int i = 0; i < arr.size(); ++i) sameEl[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        vector<bool> visited(arr.size(), false);
        visited[0] = true;
        int res = 0;

        while (not q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto cur{q.front()};
                q.pop();

                if (cur == arr.size() - 1) return res;

                for (const auto n : sameEl[arr[cur]]) {
                    if (not visited[n]) {
                        visited[n] = true;
                        q.push(n);
                    }
                }

                sameEl[arr[cur]].clear();

                if (cur + 1 < arr.size() and not visited[cur + 1]) {
                    visited[cur + 1] = true;
                    q.push(cur + 1);
                }

                if (cur - 1 >= 0 and not visited[cur - 1]) {
                    visited[cur - 1] = true;
                    q.push(cur - 1);
                }
            }

            ++res;
        }

        return res;
    }
};