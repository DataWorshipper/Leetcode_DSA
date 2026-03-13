typedef long long ll;
class Solution {
public:
bool f(vector<int>&freq2,vector<int>&freq1)
{
    bool flag=true;
    for(int i=0;i<26;i++)
    {
        if(freq1[i]<freq2[i])
        {
            flag=false;
            break;
        }
    }

    return flag;
}
    long long validSubstringCount(string word1, string word2) {
        ll l=0;
        ll r=0;
        vector<int>freq2(26,0);
        for(char c:word2)
        {
            int c1=c-'a';
            freq2[c1]++;
        }

          vector<int>freq1(26,0);
          ll count=0;
          int n=word1.size();
while(r<word1.size())
{
    freq1[word1[r]-'a']++;
   
    while(f(freq2,freq1)==true)
    {
        count+=(n-r);
        freq1[word1[l]-'a']--;
        l++;
    

    }

    r++;
}

return count;
    }
};