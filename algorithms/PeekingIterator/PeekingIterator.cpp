#include "bits/stdc++.h"

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int cur_, next_;
public:
    PeekingIterator(const vector<int>& nums)
            : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        cur_ = Iterator::hasNext() ? Iterator::next() : -1;
        next_ = Iterator::hasNext() ? Iterator::next() : -1;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return cur_;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int temp = cur_;
        cur_ = next_;
        next_ = Iterator::hasNext() ? Iterator::next() : -1;

        return temp;
    }

    bool hasNext() const {
        return cur_ != -1;
    }
};