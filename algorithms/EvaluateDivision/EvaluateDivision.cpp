#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> keys;

        for (size_t i = 0; i < equations.size(); ++i) {
            for (const int j : {0, 1}) if (keys.count(equations[i][j]) == 0) keys[equations[i][j]] = keys.size();
        }

        vector<vector<double>> adj(keys.size(), vector<double>(keys.size(), -1.));
        for (size_t i = 0; i < equations.size(); ++i) {
            auto a = keys.at(equations[i][0]);
            auto b = keys.at(equations[i][1]);

            adj[a][a] = adj[b][b] = 1.;
            adj[a][b] = values[i];
            adj[b][a] = 1. / values[i];
        }

        for (size_t k = 0; k < keys.size(); ++k) {
            for (size_t i = 0; i < keys.size(); ++i) {
                for (size_t j = 0; j < keys.size(); ++j) {
                    if (adj[i][j] == -1. && adj[i][k] != -1. && adj[k][j] != -1.) adj[i][j] = adj[i][k] * adj[k][j];
                }
            }
        }

        vector<double> res(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            if (keys.count(queries[i][0]) == 0 || keys.count(queries[i][1]) == 0) {
                res[i] = -1.;
                continue;
            }

            res[i] = adj[keys.at(queries[i][0])][keys.at(queries[i][1])];
        }

        return res;
    }
};