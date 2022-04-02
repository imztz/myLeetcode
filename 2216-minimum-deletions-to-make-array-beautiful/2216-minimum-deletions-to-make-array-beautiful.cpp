class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[i] == nums[j])
                ++j;
            if (j < n)
                sum += 2;
            i = j + 1;
        }
        return n - sum;
    }
};