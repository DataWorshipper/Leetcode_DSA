class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return fastPow(x, exp);
    }

private:
    double fastPow(double x, long long exp) {
        if (exp == 0) return 1.0;
        if (exp == 1) return x;
        double half = fastPow(x, exp / 2);
        if (exp % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
