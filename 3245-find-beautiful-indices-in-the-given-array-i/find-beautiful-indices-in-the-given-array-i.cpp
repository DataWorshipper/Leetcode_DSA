class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
         vector<int> A, B, res;
    int n = s.size();

   
    for (int i = 0; i + (int)a.size() <= n; i++) {
        if (s.compare(i, a.size(), a) == 0) {
            A.push_back(i);
        }
    }

   
    for (int i = 0; i + (int)b.size() <= n; i++) {
        if (s.compare(i, b.size(), b) == 0) {
            B.push_back(i);
        }
    }

    vector<int>ans;
    
    int r=0;
    for(int l=0;l<A.size();l++)
    {
     int left=A[l]-k;
     int right=A[l]+k;
     auto it=lower_bound(B.begin(),B.end(),left);
     if(it!=B.end() &&*it<=right)
     {
        ans.push_back(A[l]);
     }

    }

    return ans;



    }
};