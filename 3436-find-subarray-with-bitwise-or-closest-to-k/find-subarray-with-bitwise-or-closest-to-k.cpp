class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set<int>global,curr;
        curr.insert(nums[0]);
        for(int i=1;i<nums.size();i++)
        {   
            for(auto it:curr)
            {
                global.insert(it);
            }

            unordered_set<int>next;
            next.insert(nums[i]);
            for(auto it:curr)
            {
                next.insert(it|nums[i]);
            }
            curr=next;

        }

        for(auto it:curr)
            {
                global.insert(it);
            }
    int m=INT_MAX;
            for(auto it:global)
            {
                m=min(m,abs(k-it));
            }


            return  m;


    }
};