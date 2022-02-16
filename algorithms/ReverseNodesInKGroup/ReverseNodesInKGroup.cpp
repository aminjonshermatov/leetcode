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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *res = dummy;

        while (head != nullptr) {
            int i = 0;
            ListNode *prev = nullptr, *cur = head, *last = nullptr;
            while (i < k and cur != nullptr) {
                if (prev == nullptr) last = cur;
                auto next{cur->next};
                cur->next = prev;
                prev = cur;
                cur = next;

                head = next;
                ++i;
            }

            if (i < k) {
                head = prev;

                prev = nullptr;
                cur = head;

                while (cur != nullptr) {
                    auto next{cur->next};
                    cur->next = prev;
                    prev = cur;
                    cur = next;

                    head = next;
                }
                dummy->next = prev;
                head = nullptr;
            }
            else dummy->next = prev;
            dummy = last;
        }

        return res->next;
    }
};