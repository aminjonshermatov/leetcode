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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto *prev = slow;
        slow = slow->next;
        prev->next = nullptr;

        while (slow != nullptr) {
            auto *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        slow = prev;

        while (slow != nullptr && fast != nullptr) {
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};