class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mm = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> m(mm * n);
        for (int i = 0; i < mm; ++i) {
            for (int j = 0; j < n; ++j) {
                m[sz++] = matrix[i][j];
            }
        }
        int i = 0, j = sz - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (m[mid] == target) {
                return true;
            }
            else if (m[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }
};