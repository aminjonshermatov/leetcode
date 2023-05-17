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
  int pairSum(ListNode* head) {
    vector<int> sm;
    ListNode *prv = nullptr;
    for (auto cur = head; cur != nullptr;) {
      sm.emplace_back(cur->val);
      auto nxt = cur->next;
      cur->next = prv;
      prv = cur;
      cur = nxt;
    }

    int i = 0;
    for (auto cur = prv; cur != nullptr;) {
      sm[i++] += cur->val;
      cur = cur->next;
    }
    return *max_element(sm.begin(), sm.end());
  }
};