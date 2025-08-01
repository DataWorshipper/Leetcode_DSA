class Solution {
public:
    int minAddToMakeValid(string s) {
        int b=0;
        int cnt=0;
        for(char c:s)
        {
            if(c=='(')
            b++;
            else if(c==')')
            {
                b--;
                
            }

            if(b<0)
            {cnt++;
            b=0;
            }


            
        }

        return abs(cnt)+abs(b);
    }
};