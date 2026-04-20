class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0;
        int r=colors.size()-1;
        int ans=INT_MIN;
        while(l<r)
        {
            if(colors[r]!=colors[l])
            {
                ans=max(ans,abs(r-l));
            }
            r--;
        }
        r=colors.size()-1;
          while(l<r)
        {
            if(colors[r]!=colors[l])
            {
                ans=max(ans,abs(r-l));
            }
            l++;
        }
        return ans;


    }
};