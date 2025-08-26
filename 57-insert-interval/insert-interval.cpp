class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int st = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({st, end});
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const vector<int>& a, const vector<int>& b) {
                                  return a[0] < b[0]; 
                              });
        
       
        intervals.insert(it, newInterval);

      
        return merge(intervals);
    }
};
