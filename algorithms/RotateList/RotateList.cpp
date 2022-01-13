#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr or k == 0) return head;

        int len = 1;
        auto cur{head};

        while (cur->next != nullptr) {
            ++len;
            cur = cur->next;
        }

        k %= len;
        if (len == 1 or k == 0) return head;

        cur->next = head;
        len -= k;

        while (len--) cur = cur->next;
        auto res{cur->next};
        cur->next = nullptr;

        return res;
    }
};