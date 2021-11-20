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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *r = head, *prev = nullptr;

        while (n--) r = r->next;

        while (r != nullptr) {
            prev = l;
            l = l->next;
            r = r->next;
        }

        if (prev == nullptr) head = l->next;
        else prev->next = l->next;

        return head;
    }
};