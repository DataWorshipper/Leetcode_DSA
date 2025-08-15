class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
        return false;
        vector<int>bit(32,0);
        for(int i=0;i<32;i++)
        {
            int b=(n>>i)&1;
            if(b==1)
            bit[i]++;
        
        }
        int c=0;
        int index;
    for(int i=0;i<32;i++)
    {
        if(bit[i]>0)
        {c++;
        index=i;}
    }
    if(c>1)
    return false;
    else
    {
        if(index%2==0)
        return true;
    }
    return false;
    }
};