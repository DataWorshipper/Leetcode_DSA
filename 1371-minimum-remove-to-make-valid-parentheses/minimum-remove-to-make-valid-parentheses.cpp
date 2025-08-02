class Solution {
public:
    string minRemoveToMakeValid(string s) {
        

        stack<pair<char,int>>st;
        vector<int>index;
        for(int i=0;i<s.size();i++)
        {   
            if(s[i]>='a' &&s[i]<='z')
            continue;
            if(st.empty())
            {
                if(s[i]=='(')
                st.push({s[i],i});

                else
                index.push_back(i);

            }
            else
            {
                if(s[i]=='(')
                st.push({s[i],i});
                else
                st.pop();
            }
          


        } 

        while(!st.empty())
        {
        index.push_back(st.top().second);
        st.pop();
        }   
    unordered_map<int,int>mpp;
    for(auto it:index)
    {
        mpp[it]++;
    }

        string ans="";
for(int i=0;i<s.size();i++)
{
    if(mpp.find(i)==mpp.end())
    ans+=s[i];
}

return ans;
    }
};