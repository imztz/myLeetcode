class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        int cnt = 0, res = 0;
        while (j < n) {
            cnt += nums[j] == 0;
            while (cnt > k) {
                cnt -= nums[i] == 0;
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
};