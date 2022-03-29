class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int res = 0;
        int tmp = abs(word[0] - 'a');
        tmp = tmp > 13 ? (26 - tmp) : tmp;
        res += tmp + 1;
        for (int i = 1; i < n; ++i) {
            tmp = abs(word[i] - word[i-1]);
            tmp = tmp > 13 ? (26 - tmp) : tmp;
            res += tmp + 1;
        }
        return res;
    }
};