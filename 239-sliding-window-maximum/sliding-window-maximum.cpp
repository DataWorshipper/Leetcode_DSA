class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        vector<int>ans;
        multiset<int>ms;
        while(r<n)
        {
            ms.insert(nums[r]);
            while(r-l+1>k)
            {
                ms.erase(ms.find(nums[l]));
                l++;
            }
            if(r-l+1==k)
            {
                ans.push_back(*ms.rbegin());
            }
            r++;
        }
        return ans;
    }
};