class Solution {
public:
    int longestDecomposition(string text) {
        int l=0;
        int r=text.size()-1;
        string left="";
        string right="";
        int c1=0;
        while(l<r)
        {
            left+=text[l];
            right=text[r]+right;
            if(left==right)
            {
                c1+=2;
                left.clear();
                right.clear();
            }
            l++;
            
            r--;
        }
        if(!left.empty()||l==r)
            {
               return c1+1;
            }

        return c1;
       
    }
};