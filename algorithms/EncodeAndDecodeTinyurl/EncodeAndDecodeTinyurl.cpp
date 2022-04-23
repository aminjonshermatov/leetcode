#include "bits/stdc++.h"

using namespace std;

class Solution {
    unordered_map<int, string> store_;
    int lastIdx_ = 0;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        store_[lastIdx_] = longUrl;

        return "http://tinyurl.com/" + to_string(lastIdx_++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        list<short> l;
        for (int i = static_cast<int>(shortUrl.size()) - 1; i >= 0 && shortUrl[i] != '/'; --i) {
            l.push_front(shortUrl[i] - '0');
        }

        int key = 0;
        while (!l.empty()) {
            key = key * 10 + l.front();
            l.pop_front();
        }

        return store_[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));