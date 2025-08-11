class Solution {
public:
    int minimumLength(string s) {
        
        if(s[0]!=s[s.size()-1])
        return s.size();

        int n=s.size();
        int  i=0;
        int j=s.size()-1;
        char c=s[i];
        int length=n;
       while(i<n && j<n &&i<j)
       {


            char c=s[i];
            if(s[i]!=s[j])
            {
                return j-i+1;
            }

            while(s[i]==c &&s[j]==c&&i<=j)
            {
                i++;
                j--;
            }

            while(s[i]==c &&i<=j)
            {
                i++;
            }
            while(s[j]==c &&i<=j)
            j--;




       }
       if(i>j)
       return  0;

       else
       return j-i+1;
    



    }
};