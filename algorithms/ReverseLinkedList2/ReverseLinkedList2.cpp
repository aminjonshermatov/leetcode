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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == left or head->next == nullptr) return head;

        int idx = 1;

        ListNode *cur = nullptr;

        while (idx++ < left) {
            if (cur == nullptr) cur = head;
            else cur = cur->next;
        }

        ListNode* rev;
        if (cur == nullptr) rev = reverse(head, right - left + 1);
        else rev = reverse(cur->next, right - left + 1);

        if (cur == nullptr) head = rev;
        else cur->next = rev;

        return head;
    }

    ListNode* reverse(ListNode *head, int count) {
        ListNode    *prev = nullptr,
                    *cur = head,
                    *next = head->next;

        int idx = 0;

        while (idx++ < count) {
            cur->next = prev;
            prev = cur;
            cur = next;

            if (next != nullptr) next = next->next;
        }

        next = cur;
        cur = prev;

        while (cur->next != nullptr) cur = cur->next;
        cur->next = next;

        return prev;
    }
};