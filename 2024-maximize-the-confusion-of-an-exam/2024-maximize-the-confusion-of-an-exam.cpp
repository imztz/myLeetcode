class Solution {
public:
    int getC (string s, int k, char c) {
        int n = s.size(), i = 0, j = 0;
        int cnt = 0, res = 0;
        while (j < n) {
            cnt += s[j] == c;
            while (cnt > k) {
                cnt -= s[i] == c;
                ++i;
            }
            res = max(res, j - i + 1);
            ++j;
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getC(answerKey, k, 'T'), getC(answerKey, k, 'F'));
    }
};