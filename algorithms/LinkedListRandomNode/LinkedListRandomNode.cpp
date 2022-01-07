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
    vector<ListNode*> nodes;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distr;

    Solution(ListNode* head) : gen{rd()} {
        auto temp{head};

        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        distr = uniform_int_distribution<>{0, static_cast<int>(nodes.size() - 1)};
    }

    int getRandom() {
        auto node = nodes[distr(gen)];

        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */