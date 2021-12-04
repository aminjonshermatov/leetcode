#include "bits/stdc++.h"

using namespace std;

class StreamChecker {
private:
    struct Node {
        Node* next[26];
        bool isWord;

        Node() {
            isWord = false;

            for (auto& i : next) i = nullptr;
        }
    };


    vector<char> stream;
    Node *root, *cur;

public:
    StreamChecker(vector<string>& words) {
        root = new Node();

        for (const auto& w : words) {
            cur = root;

            for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
                if (cur->next[w[i] - 'a'] == nullptr) cur->next[w[i] - 'a'] = new Node();
                cur = cur->next[w[i] - 'a'];
            }

            cur->isWord = true;
        }
    }

    bool query(char letter) {
        stream.push_back(letter);
        cur = root;

        for (int i = static_cast<int>(stream.size()) - 1; i >= 0; --i) {
            if (cur->next[stream[i] - 'a'] != nullptr) {
                cur = cur->next[stream[i] - 'a'];
                if (cur->isWord) return true;
            }
            else break;
        }

        return false;
    }
};