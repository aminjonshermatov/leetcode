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
        ListNode *res = new ListNode(), *prev = head, *cur = res;

        while (prev != nullptr && prev->val == val) prev = prev->next;

        while (prev != nullptr) {
            if (prev->val != val) {
                cur->next = new ListNode(prev->val);
                cur = cur->next;
            }
            prev = prev->next;
        }

        return res->next;
    }
};