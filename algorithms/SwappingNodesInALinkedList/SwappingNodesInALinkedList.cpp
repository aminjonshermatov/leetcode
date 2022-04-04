#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 1;
        auto cur{head};

        cur = head;
        ListNode *front, *back;
        --k;
        while (k--) cur = cur->next;
        front = cur;

        back = head;
        while (cur != nullptr and cur->next != nullptr) {
            back = back->next;
            cur = cur->next;
        }

        swap(front->val, back->val);

        return head;
    }
};