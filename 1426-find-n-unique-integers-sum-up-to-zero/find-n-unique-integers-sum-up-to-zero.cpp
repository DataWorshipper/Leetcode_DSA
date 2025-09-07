class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>a(n);
        for(int i=0;i<n-1;i++)
        {
            a[i]=i+1;
        }

        int b=(n*(n-1))/2;
        a[n-1]=-b;
        return a;
    }
};