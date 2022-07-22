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
    ListNode* partition(ListNode* head, int x) {
        auto res_l = new ListNode(-1), res_g = new ListNode(-1);
        auto cur_l = res_l;
        auto cur_g = res_g;
        
        while (head != nullptr) {
            if (head->val < x) {
                cur_l->next = head;
                if (cur_l->next != nullptr) cur_l = cur_l->next;
            } else {
                cur_g->next = head;
                if (cur_g->next != nullptr) cur_g = cur_g->next;
            }
            head = head->next;
        }
        
        cur_l->next = res_g->next;
        cur_g->next = nullptr;
        
        return res_l->next;
    }
};
