#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> content2pathList;

        for (const auto &path : paths) {
            auto left = 0;

            auto space = path.find(' ', left);
            string folder;
            if (space != string::npos) {
                folder = path.substr(left, space);

                left = space + 1;
                while (left < path.size()) {
                    space = path.find(' ', left);
                    string file;
                    if (space != string::npos) {
                        file = path.substr(left, space - left);
                        left = space + 1;
                    } else {
                        file = path.substr(left);
                        left = path.size();
                    }

                    auto bracket = file.find('(');
                    string file_name, file_content;
                    if (bracket != string::npos) {
                        file_name = file.substr(0, bracket);
                        file_content = file.substr(bracket + 1, file.size() - bracket - 2);

                        content2pathList[file_content].emplace_back(folder + "/" + file_name);
                    }
                }
            }
        }

        for (const auto &[_, path_list] : content2pathList) if (path_list.size() > 1) res.emplace_back(path_list);

        return res;
    }
};