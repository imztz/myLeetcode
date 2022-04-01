class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        if (!n)
            return false;
        unordered_map<int, int> mp;
        for (int a : arr) {
            mp[a]++;
        }
        sort(arr.begin(), arr.end());
        for (int a : arr) {
            if (mp[a] && mp[a * 2]) {
                mp[a * 2]--;
                mp[a]--;
            }
        }
        for (int a : arr) {
            if (mp[a] > 0)
                return false;
        }
        return true;
    }
};