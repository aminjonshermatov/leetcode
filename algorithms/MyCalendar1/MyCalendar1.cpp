#include "bits/stdc++.h"

using namespace std;

class MyCalendar {
    map<int, int>  mp;

public:
    MyCalendar() { }

    bool book(int start, int end) {
        auto next = mp.upper_bound(start);

        if ((next == mp.begin() || start >= prev(next)->second) && (next == mp.end() || end <= next->first)) {
            mp[start] = end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */