#include "bits/stdc++.h"

using namespace std;

class BrowserHistory {
  vector<string> history;
  int cur = -1, len = 0;
public:
  BrowserHistory(string homepage) {
    history.emplace_back(homepage);
    len = 1;
    cur = 0;
  }

  void visit(string url) {
    if (cur + 1 >= history.size()) {
      history.emplace_back(url);
      ++cur;
      len = history.size();
    } else {
      history[++cur] = url;
      len = cur + 1;
    }
  }

  string back(int steps) {
    if (history.empty()) return {};
    cur = max(0, cur - steps);
    return history[cur];
  }

  string forward(int steps) {
    if (history.empty()) return {};
    cur = min(len - 1, cur + steps);
    return history[cur];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */