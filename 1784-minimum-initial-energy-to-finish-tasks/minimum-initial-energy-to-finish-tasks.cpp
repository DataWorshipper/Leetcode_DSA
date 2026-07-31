class Solution {
public:
 static bool cmp(vector<int>&a,vector<int>&b)
{
    return (a[1]-a[0])>(b[1]-b[0]);
}
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        vector<int>pref(tasks.size(),0);
        pref[0]=tasks[0][0];
        for(int i=1;i<tasks.size();i++)
        {
            pref[i]=pref[i-1]+tasks[i][0];
        }
        int x=INT_MIN;
        for(int i=0;i<tasks.size();i++)
        {      
            int cand=0;
            if(i==0)
            cand=tasks[0][1];
            else
             cand=pref[i-1]+tasks[i][1];
             x=max(x,cand);
        }
        return x;
    }
};