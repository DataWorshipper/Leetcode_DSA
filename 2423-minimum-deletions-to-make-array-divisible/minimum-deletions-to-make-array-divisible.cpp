class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int g = numsDivide[0];
        for(int x : numsDivide)
            g = gcd(g, x);

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(g % nums[i] == 0)
                return i;
        }

        return -1;
    }
};