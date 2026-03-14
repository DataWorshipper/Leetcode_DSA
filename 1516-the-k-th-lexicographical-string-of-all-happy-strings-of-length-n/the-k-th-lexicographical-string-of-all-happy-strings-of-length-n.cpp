class Solution {
public:
vector<string>a;

 void f(int index,char prev,int n,string s)
 {
    if(index==n)
    {
        a.push_back(s);
        return ;
    }

    if(prev=='1')
    {
        
         f(index+1,'a',n,s+'a');
           f(index+1,'b',n,s+'b');
             f(index+1,'c',n,s+'c');

    }
    else
    {
        if(prev=='a')
        {
             f(index+1,'b',n,s+'b');
             f(index+1,'c',n,s+'c'); 
        }

        else if(prev=='b')
        {
              f(index+1,'a',n,s+'a');
             f(index+1,'c',n,s+'c');
        }
        else
        {
           
         f(index+1,'a',n,s+'a');
           f(index+1,'b',n,s+'b'); 
        }
    }
 }

    string getHappyString(int n, int k) {
        f(0,'1',n,"");
        sort(a.begin(),a.end());
        if(a.size()<k)
        {
            return  "";
        }
        else
        {
            return a[k-1];
        }

        return "";
    }
};