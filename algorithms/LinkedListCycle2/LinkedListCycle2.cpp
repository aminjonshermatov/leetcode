#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,
                 *fast = head,
                 *entry = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }

                return entry;
            }
        }

        return nullptr;
    }
};