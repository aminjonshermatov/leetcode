#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans;
    ans.reserve(spells.size());
    for (auto s : spells) {
      ans.emplace_back(potions.end() - lower_bound(potions.begin(), potions.end(), (success + s - 1) / s));
    }
    return ans;
  }
};