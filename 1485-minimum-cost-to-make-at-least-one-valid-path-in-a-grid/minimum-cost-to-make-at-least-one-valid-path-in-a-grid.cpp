class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        while(!dq.empty())
        {
            int x=dq.front().first;
            int y=dq.front().second;
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int cost=(grid[x][y]==i+1)?0:1;
                if(dist[x][y]+cost<dist[nx][ny])
                {
                    dist[nx][ny]=dist[x][y]+cost;
                    if(cost==0)
                    dq.push_front({nx,ny});
                    else
                    dq.push_back({nx,ny});
                }
            }
        }

        return dist[m-1][n-1];
    }
};