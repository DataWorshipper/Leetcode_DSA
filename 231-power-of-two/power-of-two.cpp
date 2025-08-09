
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; // 0 is not a power of two
        }
        return (n & (n - 1)) == 0; // Check if n is a power of two
    
    }
};