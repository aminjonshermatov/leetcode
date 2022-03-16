#include "bits/stdc++.h"

using namespace std;

class RandomizedSet {
    unordered_set<int> uniq;
    vector<int> nums;

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (uniq.count(val) > 0) return false;

        uniq.insert(val);
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (uniq.count(val) == 0) return false;

        uniq.erase(val);
        return true;
    }

    int getRandom() {
        int randNum;

        do { randNum = nums[rand() % nums.size()]; } while (uniq.count(randNum) == 0);

        return randNum;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */