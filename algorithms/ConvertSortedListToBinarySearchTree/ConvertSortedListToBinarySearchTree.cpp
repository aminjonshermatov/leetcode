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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode *prv = nullptr, *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      prv = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    auto cur_node = new TreeNode(slow->val);
    if (prv != nullptr) {
      prv->next = nullptr;
      cur_node->left = sortedListToBST(head);
    }
    cur_node->right = sortedListToBST(slow->next);

    return cur_node;
  }
};