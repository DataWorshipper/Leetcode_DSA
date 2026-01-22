class Solution {
public:
bool check(int d,vector<int>& price, int k)
{
    int cnt=1;
    int lastbuy=price[0];
    for(int i=1;i<price.size();i++)
    {
        if(price[i]-lastbuy>=d)
        {
            cnt++;
            lastbuy=price[i];
        }
    }
    return (cnt>=k);
}
    int maximumTastiness(vector<int>& price, int k) {
        
        int low=0;
        sort(price.begin(),price.end());
        int high=price.back()-price[0];
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,price,k)==true)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};