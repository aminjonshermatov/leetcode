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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = nullptr, *cur = head, *next = head->next, *res = next;

        while (cur != nullptr && next != nullptr) {
            auto temp{next->next};
            next->next = cur;
            cur->next = temp;

            if (prev != nullptr) prev->next = next;
            prev = cur;

            cur = temp;

            if (temp != nullptr) next = temp->next;
        }

        return res;
    }
};