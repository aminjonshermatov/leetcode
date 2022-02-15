#include "bits/stdc++.h"

using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *prev;
        ListNode *next;
    };

    ListNode *head, *tail;
    int size_;

    inline auto getNode(int index) -> ListNode* {
        ListNode *cur;
        if (index > size_ / 2) {
            cur = tail->prev;
            int idx = size_ - index - 1;
            while (idx-- > 0 and cur != nullptr) cur = cur->prev;
        } else {
            cur = head->next;
            int idx = 0;
            while (idx++ < index and cur != nullptr) cur = cur->next;
        }
        return cur;
    }
public:

    MyLinkedList() {
        head = new ListNode{-1, nullptr, nullptr};
        tail = new ListNode{-1, nullptr, nullptr};

        head->next = tail;
        tail->prev = head;
        size_ = 0;
    }

    int get(int index) {
        if (index < 0 or index >= size_) return -1;

        return (getNode(index))->val;
    }

    void addAtHead(int val) {
        auto next{head->next};
        head->next = new ListNode{val, head, next};
        next->prev = head->next;

        ++size_;
    }

    void addAtTail(int val) {
        auto prev = tail->prev;
        tail->prev = new ListNode{val, prev, tail};
        prev->next = tail->prev;

        ++size_;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 or index > size_) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size_) {
            addAtTail(val);
            return;
        }

        auto cur{getNode(index)};

        auto prev{cur->prev};
        auto next{cur};
        prev->next = new ListNode{val, prev, next};
        next->prev = prev->next;

        ++size_;
    }

    void deleteAtIndex(int index) {
        if (index < 0 or index >= size_) return;

        auto cur{getNode(index)};

        auto prev{cur->prev};
        auto next{cur->next};

        prev->next = next;
        next->prev = prev;

        --size_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */