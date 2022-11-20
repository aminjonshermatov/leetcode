#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0, sum=0, sign=1;
        stack<int>st;
        const int N(s.size());

        for(int i = 0; i < N; ++i) {
            if(isdigit(s[i])) {
                sum= s[i] - '0';
                while(i + 1 < N && isdigit(s[i + 1])) sum = sum * 10 + (s[++i] -'0');
                res += sum * sign;
            } else if(s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if(s[i] == ')') {
                int xsign = st.top(); st.pop();
                int xresult = st.top(); st.pop();
                res = res * xsign + xresult;
            }
        }

        return res;
    }
};