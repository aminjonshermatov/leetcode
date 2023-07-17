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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto reverse = [&](ListNode *node) -> ListNode* {
      ListNode *prv = nullptr;
      for (auto cur = node; cur != nullptr;) {
        auto nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
      }
      return prv;
    };

    auto a = reverse(l1);
    auto b = reverse(l2);
    auto res = new ListNode(-1);
    auto cur = res;
    for (int rem = 0; a != nullptr || b != nullptr || rem != 0; ) {
      int sm = rem;
      if (a != nullptr) {
        sm += a->val;
        a = a->next;
      }
      if (b != nullptr) {
        sm += b->val;
        b = b->next;
      }
      auto [q, r] = div(sm, 10);
      cur->next = new ListNode(r);
      cur = cur->next;
      rem = q;
    }
    return reverse(res->next);
  }
};