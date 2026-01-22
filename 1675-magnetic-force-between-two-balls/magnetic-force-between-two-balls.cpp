class Solution {
public:
bool check(int d,vector<int>& position, int m)
{
    int lastplaced=position[0];
    int cnt=1;

    for(int i=1;i<position.size();i++)
    {
        if(position[i]-lastplaced>=d)
        {
            cnt++;
            lastplaced=position[i];
        }
    }
    
    if(cnt>=m)
    return true;
    else
    return false;

}
    int maxDistance(vector<int>& position, int m) {
        int low=0;
        sort(position.begin(), position.end());

        int high=*max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,position,m))
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