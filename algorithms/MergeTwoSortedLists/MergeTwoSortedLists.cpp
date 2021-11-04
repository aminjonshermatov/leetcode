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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(), *res = temp;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        while (l1 != nullptr) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }

        return res->next;
    }
};