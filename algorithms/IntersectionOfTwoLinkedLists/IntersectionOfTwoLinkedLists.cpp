#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool endA = false, endB = false;
        auto curA{headA}, curB{headB};

        while (curA != nullptr and curB != nullptr) {
            if (curA == curB) return curA;

            curA = curA->next;
            if (curA == nullptr and not endA) {
                curA = headB;
                endA = true;
            }

            curB = curB->next;
            if (curB == nullptr and not endB) {
                curB = headA;
                endB = true;
            }
        }

        return nullptr;
    }
};