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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1, head);
        ListNode *prev = dummy;

        while (head != nullptr) {
            if (head->next != nullptr and head->val == head->next->val) {
                while (head->next != nullptr and head->val == head->next->val) head = head->next;

                prev->next = head->next;
            } else {
                prev = prev->next;
            }

            head = head->next;
        }

        return dummy->next;
    }
};