#include "bits/stdc++.h"

using namespace std;

class MyCalendarThree {
    multiset<pair<int, int>> ss;

public:
    MyCalendarThree() = default;

    int book(int start, int end) {
        ss.insert({start, 1});
        ss.insert({end, -1});

        int ans = 0, cur = 0;
        for (auto [_, t] : ss) {
            cur += t;
            ans = max(ans, cur);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */