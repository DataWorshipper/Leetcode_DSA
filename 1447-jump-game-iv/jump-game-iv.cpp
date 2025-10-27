#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> val_to_indices;
        for (int i = 0; i < n; i++) {
            val_to_indices[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();

                // reached the last index
                if (i == n - 1) return steps;

                // move to i-1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // move to i+1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // move to all j where arr[i] == arr[j]
                for (int j : val_to_indices[arr[i]]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }

                 val_to_indices[arr[i]].clear();
            
            }
            steps++;
        }

        return -1; 
    }
};
