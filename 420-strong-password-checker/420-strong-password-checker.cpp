class Solution {
public:
    int strongPasswordChecker(string password) {

        int s = password.size();
        int a = 0, A = 0, number = 0;

        for (int i = 0; i < s; ++i){
            if (password[i] >= 'a' && password[i] <= 'z') a = 1;
            else if (password[i] >= 'A' && password[i] <= 'Z') A = 1;
            else if (password[i] >= '0' && password[i] <= '9') number = 1;
        }

        int dif = a + A + number;

        if (s < 5) return 6-s;
        if (s == 5){
            if (dif >= 2) return 1;
            else return 2;
        }

        int res = 0;
        if (s <= 20){
            char last = password[0];
            int count = 1;
            for (int i = 1; i < s; ++i){
                if (password[i] == last){
                    count ++;
                }else{
                    res += count / 3;
                    last = password[i];
                    count = 1;
                }
            }
            res += count / 3;
            return max(res, 3 - dif);
        }

        vector<int> remainder(3);

        char last = password[0];
        int count = 1;
        for (int i = 1; i < s; ++i){
            if (password[i] == last){
                count ++;
            }else{
                if (count >= 3) remainder[count % 3] ++;
                res += count / 3;
                last = password[i];
                count = 1;
            }
        }

        if (count >= 3) remainder[count % 3] ++;
        res += count / 3;

        int del = s - 20;
        if (remainder[0] > del){
            return del + max(res - del, 3 - dif);
        }else if (remainder[0] + 2 * remainder[1] > del){
            return del + max(res - remainder[0] - (del-remainder[0]) / 2, 3-dif);
        }else return del + max(res - remainder[0] - remainder[1] - (del - remainder[0] - 2*remainder[1]) / 3, 3 - dif);

        return 0;
    }
};
