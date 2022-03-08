#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        visited[start] = true;
        return dfs(arr, visited, start);
    }

    bool dfs(vector<int>& arr, vector<bool>& v, int s) {
        if (arr[s] == 0) return true;

        bool res = false;

        if (s + arr[s] < arr.size() && !v[s + arr[s]]) {
            v[s + arr[s]] = true;
            res = dfs(arr, v, s + arr[s]);
            v[s + arr[s]] = false;
        }

        if (res) return true;

        if (s - arr[s] >= 0 && !v[s - arr[s]]) {
            v[s - arr[s]] = true;
            res = dfs(arr, v, s - arr[s]);
            v[s - arr[s]] = false;
        }

        return res;
    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = static_cast<int>(arr.size());

        vector<bool> visited(n, false);
        visited[start] = true;
        queue<int> q;
        q.push(start);

        while (not q.empty()) {
            auto cur{q.front()}; q.pop();

            if (arr[cur] == 0) return true;

            if (cur - arr[cur] >= 0 and not visited[cur - arr[cur]]) {
                visited[cur - arr[cur]] = true;
                q.push(cur - arr[cur]);
            }

            if (cur + arr[cur] < n and not visited[cur + arr[cur]]) {
                visited[cur + arr[cur]] = true;
                q.push(cur + arr[cur]);
            }
        }

        return false;
    }
};