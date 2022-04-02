class Solution {
public:
    long long makePalindrome (int n, int l, int intLength) {
        string s = to_string(n);
        string t = s;
        if (intLength % 2) {
            for (int i = l - 2; i >= 0; --i) {
                t.push_back(s[i]);
            }
        } else {
            for (int i = l - 1; i >= 0; --i) {
                t.push_back(s[i]);
            }
        }
        return stoll(t);
    }

    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int l = (intLength + 1) / 2;
        int start = pow(10, l-1) - 1;
        int limit = pow(10, l) - 1;

        vector<long long> res;

        for (auto k : queries) {
            if (start + k > limit)
                res.push_back(-1);
            else
                res.push_back(makePalindrome(start + k, l, intLength));
        }
        return res;
    }
};