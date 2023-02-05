class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n(s.size());
        const int k(p.size());

        array<int, 26> f1{}, f2{};
        fill(f1.begin(), f1.end(), 0);
        fill(f2.begin(), f2.end(), 0);

        for (const auto ch : p) ++f2[ch - 'a'];

        auto ok = [&]() {
            for (int i = 0; i < 26; ++i) if (f1[i] != f2[i]) return false;
            return true;
        };

        vector<int> res;
        for (int ss = 0, ee = 0; ee < n; ++ee) {
            ++f1[s[ee] - 'a'];
            if (ee - ss >= k) --f1[s[ss++] - 'a'];
            if (ok()) res.emplace_back(ss);
        }

        return res;
    }
};