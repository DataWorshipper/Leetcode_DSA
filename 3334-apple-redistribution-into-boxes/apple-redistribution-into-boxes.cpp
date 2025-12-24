class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s=accumulate(apple.begin(),apple.end(),0);
        int a=accumulate(capacity.begin(),capacity.end(),0);
        
        sort(capacity.begin(),capacity.end());
        int c=0;
        int sum=0;
        for(int i=capacity.size()-1;i>=0;i--)
        {
            if(sum<s)
            {
                sum+=capacity[i];
                c++;
            }
            else
            break;
        } 
return c;

    }
};