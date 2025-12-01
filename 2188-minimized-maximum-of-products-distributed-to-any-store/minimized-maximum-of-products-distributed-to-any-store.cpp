class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int high=*max_element(quantities.begin(),quantities.end());
            int low=1;
            int ans=0;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int sum=0;
                for(int i=0;i<quantities.size();i++)
                {
                        int q=quantities[i];
                    sum+=(q+mid-1)/mid;
                }
                
             if(sum<=n)
                {   ans=mid;
                     high=mid-1;
                }
                else
                low=mid+1;
            }

            return ans;
    }
};