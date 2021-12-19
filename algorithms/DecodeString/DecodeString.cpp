#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string decoded;
        stack<pair<int, string>> st;
        int curNumber = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')  {
                curNumber = curNumber * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                st.push({curNumber, ""});
                curNumber = 0;
            } else if (s[i] == ']') {
                string temp;

                auto [count, str] = st.top();
                st.pop();

                while (count-- > 0) {
                    temp.append(str);
                }

                if (st.empty()) {
                    decoded.append(temp);
                } else {
                    st.top().second.append(temp);
                }
            } else {
                if (st.empty()) {
                    decoded.push_back(s[i]);
                } else {
                    st.top().second.push_back(s[i]);
                }
            }
        }

        return decoded;
    }
};