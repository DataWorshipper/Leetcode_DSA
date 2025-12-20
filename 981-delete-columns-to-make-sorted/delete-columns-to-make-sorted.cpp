class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_map<int,vector<char>>mpp;
        int len=strs[0].size();
        for(int i=0;i<len;i++)
        {
            int index=i;
            for(int j=0;j<strs.size();j++)
            {
                mpp[index].push_back(strs[j][index]);
            }

        }
        int c=0;
        for(auto it:mpp){
            vector<char>v=it.second;
            if(is_sorted(v.begin(),v.end())==false)
            c++;
        }
        return c;

    }
};