class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int prev=INT_MIN;
        int c=0;
        for(auto it:intervals)
        {
            int start=it[0];
            int end=it[1];
            if(prev<=start)
            {
                prev=end;
            }   

            else
            c++;
         }
         return c;
    }
};