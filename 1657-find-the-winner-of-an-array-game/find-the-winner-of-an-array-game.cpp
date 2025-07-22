class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n)
        return *max_element(arr.begin(),arr.end());

        int curr=arr[0];
        int wins=0;
        for(int i=1;i<n;i++)
        {
            if(curr>arr[i])
            {
                wins++;
            }
            else
            {
                curr=arr[i];
                wins=1;
            }
            if(wins>=k)
            return curr;
        }
        return *max_element(arr.begin(),arr.end());

    }
};