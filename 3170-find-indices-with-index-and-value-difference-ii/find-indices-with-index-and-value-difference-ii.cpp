class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int a, int b) {
        multiset<pair<int,int>>s;
        int j=0;
        int i=a;
        int n=nums.size();
        if(n<=a)
        return {-1,-1};

        for(int k=a;k<n;k++)
        {
            s.insert({nums[k],k});
        }

        while(i<n &&j<n)
        {
            int x=nums[j];
            int first=x-b;
            int sec=x+b;
            auto it = s.lower_bound({x + b, -1});
if (it != s.end()) {
    
    return {j, it->second};
}
auto it2 = s.lower_bound({x - b, INT_MAX});
if (it2 != s.begin()) {
    --it2; 
    return {j, it2->second};
}
s.erase({nums[i], i});
++i;
++j;





        }

        return {-1,-1};
    }
};