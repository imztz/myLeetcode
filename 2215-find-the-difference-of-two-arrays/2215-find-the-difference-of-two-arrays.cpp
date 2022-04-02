class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ss1, ss2;
        for (int n : nums1)
            ss1.insert(n);
        for (int n : nums2)
            ss2.insert(n);
        vector<vector<int>> res(2);
        for (int s : ss1) {
            if (!ss2.count(s)) {
                res[0].push_back(s);
            }
        }
        for (int s : ss2) {
            if (!ss1.count(s)) {
                res[1].push_back(s);
            }
        }
        return res;
    }
};