class Solution {
public:
bool check(int x,int m,int n,int k)

{
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int a=x/i;
        ans+=min(a,n);
    }
    if(ans>=k)
    return true;
    else
    return false;
}
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,m,n,k))
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