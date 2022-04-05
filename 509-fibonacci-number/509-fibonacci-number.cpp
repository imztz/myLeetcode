class Solution {
public:
    typedef int ll;
    struct Matrix {
        ll m[2][2];
    };
    Matrix mul(Matrix a, Matrix b) {
        Matrix res;
        for (ll i = 0; i < 2; ++i) {
            for (ll j = 0; j < 2; ++j) {
                res.m[i][j] = 0;
                for (ll k = 0; k < 2; ++k) {
                    res.m[i][j] += a.m[i][k] * b.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix poww(Matrix a, ll n) {
        Matrix res;
        memset(res.m, 0, sizeof(res.m));
        for (int i = 0; i < 2; ++i) res.m[i][i] = 1;
        Matrix f = a;
        while (n) {
            if (n&1) res = mul(res, f);
            f = mul(f, f);
            n>>=1;
        }
        return res;
    }
    int fib(int n) {
        if (n < 2)
            return n;
        Matrix res, t;
        memset(t.m, 0, sizeof(t.m));
        t.m[0][0] = 1;
        res.m[0][0] = 1, res.m[0][1] = 1, res.m[1][0] = 1, res.m[1][1] = 0;
            
        res = poww(res, n - 1);
        res = mul(res, t);
        return res.m[0][0];
    }
};