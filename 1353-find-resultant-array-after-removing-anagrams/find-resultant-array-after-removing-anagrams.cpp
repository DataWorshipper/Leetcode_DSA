class Solution {
public:
    bool anagram(string s1,string s2)
    {
        map<char,int>mpp1;
         map<char,int>mpp2;
        for(auto it:s1)
        {
            mpp1[it]++;
        }
         for(auto it:s2)
        {
            mpp2[it]++;
        }
        return mpp1==mpp2;

    }
    vector<string> removeAnagrams(vector<string>& words) {

         stack<string>st;
         for(int i=0;i<words.size();i++)
         {
            if(st.empty()||!anagram(words[i],st.top()))
            {
                st.push(words[i]);
            }
            if(anagram(st.top(),words[i]))
            {
                continue;
            }

         }

         vector<string>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};