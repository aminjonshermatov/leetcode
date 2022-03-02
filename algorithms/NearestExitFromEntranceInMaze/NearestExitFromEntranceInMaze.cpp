#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int si = entrance[0];
        const int sj = entrance[1];

        const int n = static_cast<int>(maze.size());
        const int m = static_cast<int>(maze[0].size());

        const function<bool(const int, const int)> isExit = [&](const int i, const int j) -> bool {
            return i < 0 or i >= n or j < 0 or j >= m;
        };

        queue<pair<int, int>> q;
        q.push({si, sj});
        maze[si][sj] = '+';

        int dis = 1;
        while (not q.empty()) {
            int sz = static_cast<int>(q.size());

            while (sz-- > 0) {
                auto [i, j] = q.front(); q.pop();

                if (i - 1 >= 0 and maze[i - 1][j] == '.') {
                    if (isExit(i - 2, j) or isExit(i - 1, j - 1) or isExit(i - 1, j + 1)) return dis;
                    maze[i - 1][j] = '+';
                    q.push({i - 1, j});
                }

                if (j + 1 < m and maze[i][j + 1] == '.') {
                    if (isExit(i - 1, j + 1) or isExit(i, j + 2) or isExit(i + 1, j + 1)) return dis;
                    maze[i][j + 1] = '+';
                    q.push({i, j + 1});
                }

                if (i + 1 < n and maze[i + 1][j] == '.') {
                    if (isExit(i + 1, j + 1) or isExit(i + 2, j) or isExit(i + 1, j - 1)) return dis;
                    maze[i + 1][j] = '+';
                    q.push({i + 1, j});
                }

                if (j - 1 >= 0 and maze[i][j - 1] == '.') {
                    if (isExit(i + 1, j - 1) or isExit(i, j - 2) or isExit(i - 1, j - 1)) return dis;
                    maze[i][j - 1] = '+';
                    q.push({i, j - 1});
                }

            }

            ++dis;
        }

        return -1;
    }
};