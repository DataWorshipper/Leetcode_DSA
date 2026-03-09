class Solution {
public:
    unordered_map<int,int> memo;

    int dfs(int n){
        if(n<=1) return n;
        if(memo.count(n)) return memo[n];

        int by2 = n%2 + dfs(n/2);
        int by3 = n%3 + dfs(n/3);

        return memo[n] = 1 + min(by2, by3);
    }

    int minDays(int n) {
        return dfs(n);
    }
};