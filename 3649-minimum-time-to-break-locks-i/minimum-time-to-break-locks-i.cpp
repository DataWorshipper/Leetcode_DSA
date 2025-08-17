class Solution {
public:
    int n, k;
    int answer = INT_MAX;

    void f(vector<int>& a, vector<bool>& used, vector<int>& path) {
        if(path.size() == n) {
          
            int x = 1;
            int t = path[0];
            x += k;
            for(int i = 1; i < n; i++) {
                t += ceil((double)path[i] / x);
                x += k;
            }
            answer = min(answer, t);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(used[i]) continue;
            used[i] = true;
            path.push_back(a[i]);
            f(a, used, path);
            path.pop_back();
            used[i] = false;
        }
    }

    int findMinimumTime(vector<int>& strength, int kk) {
        n = strength.size();
        k = kk;
        vector<bool> used(n, false);
        vector<int> path;
        f(strength, used, path);
        return answer;
    }
};
