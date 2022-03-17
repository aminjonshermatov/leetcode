#include "bits/stdc++.h"

using namespace std;

class RecentCounter {
    list<int> calls;
    static constexpr int OFFSET = 3'000;

public:
    RecentCounter() = default;

    int ping(int t) {
        calls.push_back(t);

        while (not calls.empty() and calls.front() < t - OFFSET) calls.pop_front();

        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */