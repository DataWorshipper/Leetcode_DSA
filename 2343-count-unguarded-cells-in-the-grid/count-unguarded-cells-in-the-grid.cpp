typedef long long ll;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

       
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<array<int,3>> q; 

        for(auto &g : guards){
            vis[g[0]][g[1]] = 2;
            q.push({g[0], g[1], -1});
        }
        for(auto &w : walls){
            vis[w[0]][w[1]] = 3;
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            auto [x, y, d] = q.front();
            q.pop();

            if(d == -1){
              
                for(int k=0;k<4;k++){
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        if(vis[nx][ny] == 0){
                            vis[nx][ny] = 1;
                            q.push({nx, ny, k});
                        }
                        else if(vis[nx][ny] == 1){
                            q.push({nx, ny, k});
                        }
                       
                    }
                }
            }
            else{
            
                int nx = x + dx[d], ny = y + dy[d];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(vis[nx][ny] == 0){
                        vis[nx][ny] = 1;
                        q.push({nx, ny, d});
                    }
                    else if(vis[nx][ny] == 1){
                        q.push({nx, ny, d});
                    }
               
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};
