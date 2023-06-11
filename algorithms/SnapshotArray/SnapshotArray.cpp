#include "bits/stdc++.h"

using namespace std;

class SnapshotArray {
  unordered_map<int, map<int, int>> hist;
  int cur_snap = 0;
public:
  SnapshotArray(int length) { }

  void set(int index, int val) {
    hist[index][cur_snap] = val;
  }

  int snap() {
    return cur_snap++;
  }

  int get(int index, int snap_id) {
    auto up = hist[index].upper_bound(snap_id);
    return up == hist[index].begin() ? 0 : prev(up)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */