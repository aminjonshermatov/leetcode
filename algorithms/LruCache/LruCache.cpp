#include "bits/stdc++.h"

using namespace std;

class LRUCache {
    int capacity_;
    using it_t = list<pair<int, int>>::iterator;
    unordered_map<int, it_t> keys;
    list<pair<int, int>> vals;

public:
    LRUCache(int capacity) : capacity_{capacity} { }

    int get(int key) {
        if (keys.count(key) == 0) return -1;

        auto cur{*keys[key]};
        vals.erase(keys[key]);
        vals.push_back(cur);
        auto last{vals.end()};
        --last;
        keys[key] = last;

        return cur.second;
    }

    void put(int key, int value) {
        if (keys.count(key) > 0) vals.erase(keys[key]);

        vals.emplace_back(key, value);
        auto last{vals.end()};
        --last;
        keys[key] = last;

        if (vals.size() > capacity_) {
            keys.erase(keys.find(vals.front().first));
            vals.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */