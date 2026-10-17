class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double>left,right;
        int l=0;
        int r=0;
        int n=nums.size();
        vector<double>ans;
        while(r<n)
        {
            if(left.empty()||nums[r]<*left.rbegin())
            {
                left.insert(nums[r]);
            }
            else
            {
                right.insert(nums[r]);
            }
            if(left.size()>right.size()+1)
            {
                int val=*left.rbegin();
                left.erase(prev(left.end()));
                right.insert(val);

            }
            else if(right.size()>left.size()+1)
            {
                int val=*right.begin();
                right.erase(right.begin());
                left.insert(val);
            }
            if(r-l+1>k)
            {
                int val=nums[l];
                auto idx=left.find(val);
                if(idx!=left.end())
                {
                    left.erase(left.find(val));
                }
                else
                {
                    right.erase(right.find(val));
                }
                if(left.size()>right.size()+1)
            {
                int val=*left.rbegin();
                left.erase(prev(left.end()));
                right.insert(val);

            }
            else if(right.size()>left.size()+1)
            {
                int val=*right.begin();
                right.erase(right.begin());
                left.insert(val);
            }
                l++;
            }
            if(r-l+1==k)
            {
                if(k%2==1)
                {
                    if(left.size()>right.size())
                    {
                        ans.push_back(*left.rbegin());
                    }
                    else
                    ans.push_back(*right.begin());
                }
                else
                {
                    double a=*left.rbegin();
                    double b=*right.begin();
                    double val=(a+b)/2;
                    ans.push_back(val);
                }
            }
            r++;
        }
        return ans;


    }
};