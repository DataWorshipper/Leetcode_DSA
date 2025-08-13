class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logRes = log10(n) / log10(3);
        return floor(logRes) == ceil(logRes);  
    }
};