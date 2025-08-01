class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        

        vector<pair<int,int>>diff;
        for(int i=0;i<reward1.size();i++)
        {
            diff.push_back({(reward1[i]-reward2[i]),i});
        }

        sort(diff.rbegin(),diff.rend());

        
        int c=0;
        for(int i=0;i<k;i++)
        {
            c+=reward1[diff[i].second];
        }
        for(int i=k;i<reward1.size();i++)
        {
            c+=reward2[diff[i].second];
        }
        return c;
    }
};