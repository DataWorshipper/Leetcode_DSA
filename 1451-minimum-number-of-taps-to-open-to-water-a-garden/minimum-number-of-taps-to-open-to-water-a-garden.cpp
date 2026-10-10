class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> intervals;

for (int i = 0; i <= n; i++) {
    int l = max(0, i - ranges[i]);
    int r = min(n, i + ranges[i]);
    intervals.push_back({l, r});
}

sort(intervals.begin(), intervals.end());
int covered=0;
int i=0;
int ans=0;
while(covered<n)
{
        int farthest=covered;
        while(i<=n && intervals[i].first<=covered)
        {
            farthest=max(farthest,intervals[i].second);
            i++;
        }
        if(farthest==covered)
        return -1;
        else
        {covered=farthest;
        ans++;
        }

}
return ans;
    }
};