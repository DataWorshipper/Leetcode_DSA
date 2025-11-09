class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {

        bool cycle = (edges.size() == n);

        vector<int> seq;

        if(cycle){
            // cycle seq
            seq.push_back(1);
            for(int i=2;i<=n;i+=2) seq.push_back(i);
            for(int i=(n%2 ? n : n-1); i>=3; i-=2) seq.push_back(i);
        } 
        else {
            // path seq
            for(int i=1;i<=n;i+=2) seq.push_back(i);
            for(int i=(n%2 ? n-1 : n); i>=2; i-=2) seq.push_back(i);
        }

        long long ans = 0;

        if(cycle){
            for(int i=0;i<n;i++){
                ans += 1LL * seq[i] * seq[(i+1)%n];
            }
        } 
        else {
            for(int i=0;i<n-1;i++){
                ans += 1LL * seq[i] * seq[i+1];
            }
        }

        return ans;
    }
};
