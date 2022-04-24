#include "bits/stdc++.h"

using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> starts_;
    unordered_map<string, pair<int, int>> times_;

public:
    UndergroundSystem() = default;

    void checkIn(int id, string stationName, int t) {
        starts_[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto it = starts_.find(id);

        string key = it->second.first + "#" + stationName;
        times_[key].first += t - it->second.second;
        ++times_[key].second;

        starts_.erase(it);
    }

    double getAverageTime(string startStation, string endStation) {
        auto it = times_[startStation + "#" + endStation];

        return static_cast<double>(it.first) / static_cast<double>(it.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */