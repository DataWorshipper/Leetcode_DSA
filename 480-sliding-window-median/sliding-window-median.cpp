class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>left,right;
        vector<double>ans;

        int r=0;
        int l=0;
        int n=nums.size();
        while(r<n)
        {
            if(left.empty()||nums[r]<=*left.rbegin())
            {
                left.insert(nums[r]);
            }
            else
            right.insert(nums[r]);

            if(left.size()>right.size()+1)
            {
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
            else if(right.size()>left.size()+1)
            {
                left.insert(*right.begin());
                right.erase(right.begin());

            }
  if(r-l+1>k)
            {

                int remove=nums[l];
    auto it = left.find(nums[l]);
if (it != left.end()) {
    left.erase(it);
} else {
    right.erase(right.find(nums[l])); 
}


               
               
               


                     if(left.size()>right.size()+1)
            {
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
            else if(right.size()>left.size()+1)
            {
                left.insert(*right.begin());
                right.erase(right.begin());

            }
                l++;


            }
           if(r-l+1==k)
            {   if(left.size()==right.size())
            {
                int a1=*left.rbegin();
                int b1=*right.begin();
                double med=(((long long)a1+(long long)b1))/2.0;
                ans.push_back(med);}
                else if(left.size()>right.size())
                {
                    ans.push_back(*left.rbegin());
                }
                else
                ans.push_back(*right.begin());
            }
          

            r++;
        }

        return ans;
    }
};