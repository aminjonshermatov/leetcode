#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // <value, index>
        map<int, int> hashMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(target - nums[i]) > 0) {
                return {hashMap[target - nums[i]], i};
            }

            hashMap.insert({nums[i], i});
        }

        return {};
    }
};

int main() {
    Solution solution;

    vector<int> input1 = {2,7,11,15};
    for (const auto& num : solution.twoSum(input1, 9)) cout << num << ' ';
    cout << '\n';

    vector<int> input2 = {3,2,4};
    for (const auto& num : solution.twoSum(input2, 6)) cout << num << ' ';
    cout << '\n';

    vector<int> input3 = {3,3};
    for (const auto& num : solution.twoSum(input3, 6)) cout << num << ' ';
    cout << '\n';
}