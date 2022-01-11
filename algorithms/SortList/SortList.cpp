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
    ListNode* sortList(ListNode* head) {
        ListNode    *prev = nullptr,
                    *slow = head,
                    *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev == nullptr) return head;

        prev->next = nullptr;
        auto    l = sortList(head),
                r = sortList(slow);

        ListNode    *dummy = new ListNode(-1),
                    *cur = dummy;

        while (l != nullptr && r != nullptr) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }

        if (l != nullptr) cur->next = l;
        else if (r != nullptr) cur->next = r;

        return dummy->next;
    }
};