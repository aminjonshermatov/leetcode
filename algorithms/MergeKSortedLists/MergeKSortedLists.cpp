#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MinHeap {
public:
    MinHeap() : size_{0} {}

    void add(ListNode* node) {
        if (node == nullptr) return;
        heap_.push_back(node);
        ++size_;

        siftUp();
    }

    ListNode* pop() {
        assert(size_ > 0);

        auto minNode{heap_[0]};

        if (heap_[0]->next == nullptr) {
            heap_[0] = heap_[size_ - 1];
            --size_;
        }
        else
            heap_[0] = heap_[0]->next;

        siftDown();

        return minNode;
    }

    bool empty() const {
        return size_ == 0;
    }

private:
    vector<ListNode*> heap_;
    int size_;

    inline int getParentIdx(int idx) { return (idx - 1) / 2; }
    inline int getLeftChildIdx(int idx) { return idx * 2 + 1; }
    inline int getRightChildIdx(int idx) { return idx * 2 + 2; }

    void swap(int idxFirst, int idxSecond) {
        auto temp{heap_[idxFirst]};
        heap_[idxFirst] = heap_[idxSecond];
        heap_[idxSecond] = temp;
    }

    void siftUp() {
        int idx = size_ - 1;

        while (idx > 0 && heap_[getParentIdx(idx)]->val > heap_[idx]->val) {
            swap(idx, getParentIdx(idx));
            idx = getParentIdx(idx);
        }
    };

    void siftDown() {
        int idx = 0;

        while (getLeftChildIdx(idx) < size_) {
            int smallestIdx = getLeftChildIdx(idx);

            if (getRightChildIdx(idx) < size_ && heap_[getRightChildIdx(idx)]->val < heap_[smallestIdx]->val) smallestIdx = getRightChildIdx(idx);

            if (heap_[smallestIdx]->val > heap_[idx]->val) break;

            swap(idx, smallestIdx);
            idx = smallestIdx;
        }
    };
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyRes = new ListNode(), *cur = dummyRes;

        MinHeap heap;

        for (const auto& list : lists) heap.add(list);

        while (!heap.empty()) {
            cur->next = heap.pop();
            cur = cur->next;
        }

        cur->next = nullptr;

        return dummyRes->next;
    }
};