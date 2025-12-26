class Solution {
public:
    int bestClosingTime(string customers) {
        int len = customers.size();
        vector<int> y(len, 0), n(len, 0);

        y[0] = (customers[0] == 'Y');
        n[0] = (customers[0] == 'N');

        for (int i = 1; i < len; i++) {
            y[i] = y[i - 1] + (customers[i] == 'Y');
            n[i] = n[i - 1] + (customers[i] == 'N');
        }

        vector<int> ans(len + 1);

      
        ans[0] = y[len - 1];

    
        ans[len] = n[len - 1];

        for (int j = 1; j < len; j++) {
         
            int openPenalty = n[j - 1];
           
            int closedPenalty = y[len - 1] - y[j - 1];

            ans[j] = openPenalty + closedPenalty;
        }

        int a = min_element(ans.begin(), ans.end()) - ans.begin();
        return a;
    }
};
