class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        const int LOG = 32; 
    vector<int> basis(LOG, 0);

    
    for (int num : nums) {
        for (int i = LOG - 1; i >= 0; --i) {  
            if (num & (1 << i)) {
                if (basis[i] == 0) {
                    basis[i] = num;
                    break;
                } else {
                    num ^= basis[i];
                }
            }
        }
    }

    
    int max_xor = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        max_xor = max(max_xor, max_xor ^ basis[i]);
    }

    return max_xor;
    }
};