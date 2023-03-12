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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](const ListNode *lhs, const ListNode *rhs) { return lhs->val > rhs->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto node : lists) if (node != nullptr) pq.emplace(node);

    ListNode *res = new ListNode(-1);
    auto dummy = res;
    while (!pq.empty()) {
      auto cur = pq.top(); pq.pop();
      dummy->next = cur;
      dummy = dummy->next;
      if (cur->next != nullptr) pq.emplace(cur->next);
    }
    return res->next;
  }
};