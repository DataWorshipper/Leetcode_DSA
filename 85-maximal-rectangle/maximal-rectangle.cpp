class Solution {
public:


 vector<int>findnse(vector<int>nums)
 {
    stack<int>st;
    vector<int>nse(nums.size(),nums.size());
    for(int i=nums.size()-1;i>=0;i--)
    {
        while(!st.empty()&&(nums[i])<=nums[st.top()])
       { st.pop();}
        
        if(!st.empty())
        nse[i]=st.top();

        st.push(i);
    }
    return nse;
 }
  vector<int>findpse(vector<int>nums)
 {
    stack<int>st;
    vector<int>pse(nums.size(),-1);
    for(int i=0;i<nums.size();i++)
    {
        while(!st.empty()&&(nums[i])<=nums[st.top()])
      {  st.pop();}
        if(!st.empty())
        pse[i]=st.top();

        st.push(i);
    }
    return pse;
 }




    int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
        int m=matrix[0].size();
       
        vector<int>heights(m,0);

    int max_area=-1;
        for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') 
            heights[j] += 1;
         else 
            heights[j] = 0;}
                
                 vector<int> nse = findnse(heights);
            vector<int> pse = findpse(heights);

            for (int k = 0; k < m; k++) {
                int width = nse[k] - pse[k] - 1;
                int area = heights[k] * width;
                if (area > max_area) max_area = area;
            }
        
        

    }
    return max_area;
}
};