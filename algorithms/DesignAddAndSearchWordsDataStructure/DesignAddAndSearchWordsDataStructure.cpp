#include "bits/stdc++.h"

using namespace std;

class WordDictionary {
public:
    unordered_map<int, unordered_set<string>> store_;

    WordDictionary() = default;

    void addWord(string word) {
        store_[word.size()].insert(word);
    }

    bool search(string word) {
        if (store_.count(word.size()) == 0) return false;

        if (word.find('.') == string::npos) return store_[word.size()].count(word) > 0;

        for (const auto &w : store_[word.size()]) {
            int i = 0, j = 0;

            while (i < w.size() and j < word.size()) {
                if (word[j] == '.') {
                    ++i;
                    ++j;
                    continue;
                }

                if (w[i] != word[j]) break;
                ++i;
                ++j;
            }

            if (i == w.size() and j == word.size()) return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */