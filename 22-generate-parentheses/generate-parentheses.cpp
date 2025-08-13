class Solution {
public:
    void f(string &s,int open,int bal,vector<string>&ans,int n)
    {
        if(bal<0)
        return;
        if(s.size()==2*n)
        {
            if(bal==0)
            ans.push_back(s);
        }
        
        if(open<n)
        {
            s+='(';
            f(s,open+1,bal+1,ans,n);
            s.pop_back();
        }
        
        if(bal>0)
        {
            s+=')';
            f(s,open,bal-1,ans,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>ans;
        f(s,0,0,ans,n);
        return ans;
    }
};