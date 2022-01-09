#include "bits/stdc++.h"

using namespace std;

class Solution {
    void move(int &direc, pair<int, int> &pos){
        if(direc == 90){
            ++pos.first;
        } else if (direc == -90 || direc == 270) {
            --pos.first;
        } else if (direc == 0 || direc == -270) {
            ++pos.second;
        } else if (abs(direc) == 180) {
            --pos.second;
        }
    }
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> pos{0, 0};
        int direc = 0;

        for(const char ch : instructions){
            if(ch == 'L') direc -= 90;
            if(ch == 'R') direc += 90;
            direc = direc % 360;

            if(ch == 'G') move(direc, pos);
        }

        return (pos.first==0 && pos.second==0) || direc;
    }
};