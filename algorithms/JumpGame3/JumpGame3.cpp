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