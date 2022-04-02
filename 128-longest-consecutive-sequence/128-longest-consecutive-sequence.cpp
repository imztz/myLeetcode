class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nn;
        for (int num : nums) {
            nn.insert(num);
        }
        int res = 0;
        for (int n : nn) {
            int cur = n;
            if (!nn.count(cur - 1)) {
                while (nn.count(cur + 1)) {
                    ++cur;
                }
            }
            res = max(res, cur - n + 1);
        }
        return res;
    }
};