#include "bits/stdc++.h"

using namespace std;

class TimeMap {
    map<string, map<int, string>> store_;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        store_[key].emplace(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = store_.find(key);
        if (it == store_.end()) return "";

        auto found = it->second.upper_bound(timestamp);
        if (found == it->second.begin()) return "";

        return prev(found)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */