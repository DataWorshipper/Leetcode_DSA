class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long >ms;
        for(auto it:nums)
        {
            ms.insert(it);
        }
       
        long long  ops=0;
        while(ms.size()>=2)
        {   

            auto it=ms.begin();
             if(*it >=k)
            {
                break;
            }
            auto  it1=ms.begin();
            auto it2=next(ms.begin(), 1);
             long long x=*it1;
            long long y=*it2;
            ms.erase(it1);
            ms.erase(it2);
           
            ms.insert(2*min(x,y)+max(x,y));
            ops++;
            
           
            
           



        }

        return ops;
    }

};