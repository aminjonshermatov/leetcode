#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    const int n(req_skills.size());
    const int m(people.size());
    unordered_map<string, int> sk;
    for (int i = 0; i < n; ++i) {
      sk[req_skills[i]] = i;
    }
    vector<int> ps(m, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < people[i].size(); ++j) {
        if (sk.count(people[i][j]) > 0) {
          ps[i] |= 1u << sk[people[i][j]];
        }
      }
    }

    vector<uint64_t> cnt(1 << n, 1e9), mask(1 << n, 0);
    cnt[0] = 0;
    for (int i = 0; i < m; ++i) {
      for (uint64_t m = 0; m < (1 << n); ++m) {
        if (cnt[m] == 1e9 || cnt[m | ps[i]] <= cnt[m] + 1) continue;
        cnt[m | ps[i]] = cnt[m] + 1;
        mask[m | ps[i]] = mask[m] | (uint64_t(1) << i);
      }
    }
    vector<int> ids;
    for (int i = 0; i < m; ++i) {
      if (mask[(1 << n) - 1] >> i & 1) {
        ids.emplace_back(i);
      }
    }
    return ids;
  }
};