class Solution {
public:
string nonzero(string num)
{   
    int index;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]!=0)
        {
            index=i;
            break;
        }
    }
    num=num.substr(index);
    return num;
}
    string largestGoodInteger(string num) {
        num=nonzero(num);
        int l=0;
        int r=0;
        unordered_map<char,int>mpp;
        int n=num.size();
        int m=INT_MIN;
        string s="";
        while(r<n)
        {
            mpp[num[r]]++;
            while(r-l+1>3)
            {
                
                mpp[num[l]]--;
                if(mpp[num[l]]==0)
                mpp.erase(num[l]);
                l++;

            }
            if(r-l+1==3 &&mpp.size()==1)
            {   
                 
              m=max(m,stoi(num.substr(l,r-l+1)));  
            }

            r++;
        }
        if(m==INT_MIN)
        return "";
        else if(m==0)
        return "000";
        else
        return to_string(m);
        
    }
};