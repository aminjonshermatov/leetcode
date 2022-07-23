#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n(nums.size());
        ordered_set os;

        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            res[i] = os.order_of_key(nums[i]);
            os.insert(nums[i]);
        }

        return res;
    }
};
