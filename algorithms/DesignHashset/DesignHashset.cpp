#include "bits/stdc++.h"

using namespace std;

class MyHashSet {
    static constexpr size_t size_ = 15626u;
    static constexpr size_t bits_size_ = 64u;

    uint64_t data_[size_] = { 0u };

    pair<size_t, short> getAddresses_(int key) const {
        size_t idx = key / bits_size_;
        short pos = key % bits_size_; // bit position

        return { idx, pos };
    }

public:
    MyHashSet() { }

    void add(int key) {
        auto [i, p] = getAddresses_(key);

        data_[i] |= 1ull << p;
    }

    void remove(int key) {
        auto [i, p] = getAddresses_(key);

        data_[i] &= ~(1ull << p);
    }

    bool contains(int key) {
        auto [i, p] = getAddresses_(key);

        return static_cast<bool>((data_[i] >> p) & 1ull);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */