class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int low=*min_element(a.begin(),a.end());
        int high=*max_element(a.begin(),a.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int consec=0;
            int bouq=0;
            for(int i=0;i<a.size();i++)
            {
                if(a[i]<=mid)
                {
                    consec++;
                
                if(consec==k)
                {
                    consec=0;
                    bouq++;
                }}
                else
                {
                    consec=0;
                }

            }

            if(bouq>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
            
        }
        return ans;
    }
};