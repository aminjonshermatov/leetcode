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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res, *prev = head, *cur = head;

        while (prev != nullptr && prev->val == val) {
            prev = prev->next;
            cur = cur->next;
        }

        if (cur != nullptr) {
            cur = cur->next;
        }
        while (cur != nullptr && cur->val == val) {
            cur = cur->next;
        }

        res = prev;
        if (prev != nullptr) {
            prev->next = cur;
        }

        while (prev != nullptr) {
            while (cur != nullptr && cur->val == val) {
                cur = cur->next;
            }

            prev->next = cur;
            prev = cur;

            if (cur != nullptr) {
                cur = cur->next;
            }
        }

        return res;
    }
};