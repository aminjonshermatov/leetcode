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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto rev{slow->next};
        slow->next = nullptr;

        if (rev == nullptr) return;

        ListNode *prev = rev, *cur = rev->next;
        prev->next = nullptr;

        while (cur != nullptr) {
            auto temp{cur->next};
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        cur = head;
        while (cur != nullptr and prev != nullptr) {
            auto temp{cur->next};
            cur->next = prev;
            prev = prev->next;
            cur = cur->next;
            cur->next = temp;
            cur = cur->next;
        }
    }
};