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
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head, *cur = head->next, *sorted = prev;

        while (prev != nullptr) {
            while (cur != nullptr && cur->val == prev->val) {
                cur = cur->next;
            }

            prev->next = cur;
            prev = prev->next;
        }

        return sorted;
    }
};