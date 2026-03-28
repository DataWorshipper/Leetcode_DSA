

class Solution {
public:
    int minOperations(int n) {
        int maxOps = __builtin_popcount(n); 
        queue<pair<int,int>> q;
        unordered_set<int> vis;
        
        q.push({n, 0});
        vis.insert(n);
        
        int LIMIT = 2 * n; 
        
        while (!q.empty()) {
            auto [num, ops] = q.front();
            q.pop();
            
            if (num == 0) return ops;
            
            if (ops >= maxOps) continue; 
            
            for (int i = 0; i <= 20; i++) {
                int p = (1 << i);
               
                int next1 = num - p;
                if (next1 >= 0 && vis.find(next1) == vis.end()) {
                    vis.insert(next1);
                    q.push({next1, ops + 1});
                }
                
               
                int next2 = num + p;
                if (next2 <= LIMIT && vis.find(next2) == vis.end()) {
                    vis.insert(next2);
                    q.push({next2, ops + 1});
                }
            }
        }
        
        return -1; 
    }
};