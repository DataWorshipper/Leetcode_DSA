typedef long long ll;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<vector<int>> q;

        for(auto &it : guards){
            int x = it[0], y = it[1];
            vis[x][y] = 2; 
            q.push({x,y,x,y});
        }

        for(auto &it : walls){
            int x = it[0], y = it[1];
            vis[x][y] = 3; 
        }

        int nx[] = {1,-1,0,0};
        int ny[] = {0,0,1,-1};

        while(!q.empty()){
            auto a = q.front(); q.pop();

            int cx = a[0], cy = a[1], sx = a[2], sy = a[3];

            if(cx == sx && cy == sy){
                for(int i=0;i<4;i++){
                    int nx_ = cx + nx[i], ny_ = cy + ny[i];
                    if(nx_>=0 && nx_<m && ny_>=0 && ny_<n){
                        if(vis[nx_][ny_] == 0){
                            vis[nx_][ny_] = 1; 
                            q.push({nx_, ny_, sx, sy});
                        }
                        else if(vis[nx_][ny_] == 1)
                        {
                           q.push({nx_, ny_, sx, sy}); 
                        }

                    }
                }
            }
            else{
                int dx = cx - sx, dy = cy - sy;

                int nx_, ny_;
                if(dx == 0 && dy > 0)      nx_ = cx, ny_ = cy + 1;
                else if(dx == 0 && dy < 0) nx_ = cx, ny_ = cy - 1;
                else if(dx > 0 && dy == 0) nx_ = cx + 1, ny_ = cy;
                else                       nx_ = cx - 1, ny_ = cy;

                if(nx_>=0 && nx_<m && ny_>=0 && ny_<n){
                    if(vis[nx_][ny_] == 0){
                        vis[nx_][ny_] = 1;
                        q.push({nx_, ny_, sx, sy});
                    }
                     else if(vis[nx_][ny_] == 1)
                        {
                           q.push({nx_, ny_, sx, sy}); 
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
