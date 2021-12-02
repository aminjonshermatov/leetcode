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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *oddRes = new ListNode(-1),
                 *odd = oddRes,
                 *evenRes = new ListNode(-1),
                 *even = evenRes;

        int idx = 1;

        while (head != nullptr) {
            if (idx & 1) {
                odd->next = new ListNode(head->val);
                odd = odd->next;
            } else {
                even->next = new ListNode(head->val);
                even = even->next;
            }
            head = head->next;

            ++idx;
        }

        odd->next = evenRes->next;

        return oddRes->next;
    }
};