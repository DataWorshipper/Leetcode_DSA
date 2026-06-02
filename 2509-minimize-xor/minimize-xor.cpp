class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int need = __builtin_popcount(num2);
        int have = __builtin_popcount(num1);

        int x = 0;

        if (have >= need) {
            for (int b = 31; b >= 0 && need; b--) {
                if (num1 & (1 << b)) {
                    x |= (1 << b);
                    need--;
                }
            }
        } else {
            x = num1;
            need -= have;

            for (int b = 0; b < 32 && need; b++) {
                if ((x & (1 << b)) == 0) {
                    x |= (1 << b);
                    need--;
                }
            }
        }

        return x;
    }
};