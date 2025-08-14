class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> R, D;
        
      
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') R.push(i);
            else D.push(i);
        }
        
      
        while (!R.empty() && !D.empty()) {
            int rIndex = R.front(); R.pop();
            int dIndex = D.front(); D.pop();
            
            if (rIndex < dIndex) {
                
                R.push(rIndex + n);
            } else {
              
                D.push(dIndex + n);
            }
        }
        
        return R.empty() ? "Dire" : "Radiant";
    }
};
