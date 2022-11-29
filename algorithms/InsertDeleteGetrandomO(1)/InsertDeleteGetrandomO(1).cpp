class RandomizedSet {
    unordered_set<int> uniq;
    vector<int> nums;

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (uniq.count(val) > 0) return false;
        return uniq.insert(val), nums.push_back(val), true;
    }

    bool remove(int val) {
        if (uniq.count(val) == 0) return false;
        return uniq.erase(val), true;
    }

    int getRandom() {
        int res;
        do { res = nums[rand() % nums.size()]; } while (uniq.count(res) == 0);
        return res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */