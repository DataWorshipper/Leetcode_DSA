class Solution {
    int dp[501][501];
    int f(int index1,int index2,vector<int>& nums1, vector<int>& nums2)
    {
        int m=nums1.size();
        int n=nums2.size();
        if(index1==m||index2==n)
        {   
           return INT_MIN/2;
        }
        if(dp[index1][index2]!=-1)
        return dp[index1][index2];
        int ans=INT_MIN;
        int op1=nums1[index1]*nums2[index2] +max(0,f(index1+1,index2+1,nums1,nums2));
        int op2=f(index1,index2+1,nums1,nums2);
        int op3=f(index1+1,index2,nums1,nums2);
        ans=max({ans,op1,op2,op3});
        return dp[index1][index2]=ans;
        
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size();
        int n=nums2.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums1,nums2);
    }
};