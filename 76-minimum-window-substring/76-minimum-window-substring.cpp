class Solution {
public:
    unordered_map<char, int> tt, cnt;

    bool check() {
        for (auto &p : tt) {
            if (cnt[p.first] < p.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (char c : t) {
            tt[c]++;
        }
        int n = s.size(), l = 0, r = -1;
        int len = 100005, ll = -1;
        while (r < n) {
            if (tt.count(s[++r])) {
                cnt[s[r]]++;
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ll = l;
                }
                if (tt.count(s[l]))
                    --cnt[s[l]];
                ++l;
            }    
        }
        return ll == -1 ? "" : s.substr(ll, len);
    }
};