#include "bits/stdc++.h"

using namespace std;

class MyHashMap {
    constexpr static size_t table_size_ = 5701u;
    struct node {
        int     key;
        int     val;
        node    *next;
    };
    node* hash_table_[table_size_] = { nullptr };

    size_t get_hash_(int key) const {
        return (key % table_size_ + table_size_) % table_size_;
    }

public:
    MyHashMap() = default;

    void put(int key, int value) {
        size_t hash = get_hash_(key);

        node *prev = nullptr, *cur = hash_table_[hash];
        if (cur == nullptr) {
            hash_table_[hash] = new node{key, value, nullptr};
            return;
        }

        while (cur != nullptr) {
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        prev->next = new node{key, value, nullptr};
    }

    int get(int key) {
        size_t hash = get_hash_(key);

        node *cur = hash_table_[hash];
        while (cur != nullptr) {
            if (cur->key == key) return cur->val;
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        size_t hash = get_hash_(key);

        node *prev = nullptr, *cur = hash_table_[hash];
        if (cur == nullptr) return;

        while (cur != nullptr) {
            if (cur->key == key) {
                if (prev == nullptr) hash_table_[hash] = cur->next;
                else prev->next = cur->next;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */