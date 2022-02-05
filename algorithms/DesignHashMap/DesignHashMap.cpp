#include "bits/stdc++.h"

using namespace std;

struct HashNode {
    int key;
    int val;
    HashNode* prev;
    HashNode* next;
};


class MyHashMap {
public:
    constexpr static int SIZE = 1e7 + 9;
    HashNode* table_[SIZE];

    MyHashMap() = default;

    void put(int key, int value) {
        const int hash = getHash_(key);

        auto head = table_[hash];
        while (head != nullptr) {
            if (head->key == key) break;
            head = head->next;
        }

        if (head != nullptr) head->val = value;
        else table_[hash] = new HashNode{key, value, nullptr, table_[hash]};
    }

    int get(int key) {
        const int hash = getHash_(key);

        auto head = table_[hash];
        while (head != nullptr) {
            if (head->key == key) break;
            head = head->next;
        }

        return head == nullptr ? -1 : head->val;
    }

    void remove(int key) {
        const int hash = getHash_(key);

        auto head = table_[hash];
        while (head != nullptr) {
            if (head->key == key) break;
            head = head->next;
        }

        if (head != nullptr) {
            if (head->prev == nullptr) {
                table_[hash] = head->next;
            } else {
                head->prev->next = head->next;
            }
            delete head;
        }
    }

private:
    inline int getHash_(int key) const {
        return key % SIZE;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */