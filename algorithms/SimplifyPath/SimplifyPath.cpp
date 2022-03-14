#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        list<string> pathL;
        string cur;
        int dots = 0;

        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() or path[i] == '/') {
                if (dots == 2 and cur.size() == 2) {
                    if (not pathL.empty()) pathL.pop_back();
                }
                else if (not (dots == 1 and cur.size() == 1) and not cur.empty()) pathL.push_back(cur);

                cur.clear();
                dots = 0;
            } else {
                if (path[i] == '.') ++dots;
                cur.push_back(path[i]);
            }
        }

        string res;

        while (not pathL.empty()) {
            res.push_back('/');
            res.append(pathL.front());
            pathL.pop_front();
        }

        return res.empty() ? "/" : res;
    }
};