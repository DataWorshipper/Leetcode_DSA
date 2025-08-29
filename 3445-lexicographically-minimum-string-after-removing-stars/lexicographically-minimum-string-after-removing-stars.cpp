class Solution {
public:
    string clearStars(string s) {
        

        using P = pair<char,int>;

struct Compare {
    bool operator()(const P& a, const P& b) const {
        if (a.first == b.first) {
         
            return a.second < b.second;
        }
     
        return a.first > b.first;
    }
};

priority_queue<P, vector<P>, Compare> pq;

vector<bool>removed(s.size(),false);
for(int i=0;i<s.size();i++)
{
    if(s[i]!='*')
    {
        pq.push({s[i],i});
    }
    else
    {   
        if(!pq.empty())
        {
        char c=pq.top().first;
        int index=pq.top().second;

        pq.pop();
        removed[index]=true;
         removed[i]=true;}
    }
   
}

string ans="";
for(int i=0;i<s.size();i++)
{
    if(!removed[i])
    ans+=s[i];
}

return ans;

    }
};