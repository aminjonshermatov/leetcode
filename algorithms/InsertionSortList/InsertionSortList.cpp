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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = head,
                 *resTail = head;

        while (resTail != nullptr && resTail->next != nullptr) {
            auto cur = resTail->next;
            if (cur->val < resTail->val) {
                ListNode *s = res, *prev = nullptr;
                while (s->val < cur->val) {
                    prev = s;
                    s = s->next;
                }

                auto temp = s;
                while (temp->next != cur) temp = temp->next;
                temp->next = cur->next;
                if (prev == nullptr) res = cur;
                else prev->next = cur;
                cur->next = s;
            } else {
                resTail = resTail->next;
            }
        }

        return res;
    }
};