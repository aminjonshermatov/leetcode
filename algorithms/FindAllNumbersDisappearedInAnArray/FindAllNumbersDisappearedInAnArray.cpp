#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T> v) {
    out << '[';

    for (const auto& e : v) out << e << ", ";

    return out << ']';
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>&& nums) {
        unordered_set<int> uniq;

        for (const auto& n : nums) uniq.insert(n);

        size_t len = nums.size();
        vector<int> missing;
        for (int i = 1; i <= len; ++i) {
            if (uniq.count(i) == 0) {
                missing.push_back(i);
            }
        }

        return missing;
    }
};

int main() {
    Solution s;
    cout << s.findDisappearedNumbers({4,3,2,7,8,2,3,1}) << '\n';
    cout << s.findDisappearedNumbers({1,1}) << '\n';
}