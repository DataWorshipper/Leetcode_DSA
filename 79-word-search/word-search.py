class Solution:
    
    

    def exist(self, board: List[List[str]], word: str) -> bool:
        m=len(board)
        n=len(board[0])
        
        vis=[[0]*n for _ in range(m)]
        flag=False
        def dfs(i,j,idx):
            nonlocal flag
            if idx==len(word):
                flag=True
                return
            
        
            nx=[1,-1,0,0]
            ny=[0,0,1,-1]
            vis[i][j]=1
            for k in range(4):
                x=i+nx[k]
                y=j+ny[k]
                if x>=0 and x<m and y>=0 and y<n:
                    if vis[x][y]==0:
                        if word[idx]==board[x][y]:
                            dfs(x,y,idx+1)
                      
            
            vis[i][j]=0
                    
        
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]:
                    dfs(i,j,1)
                    if flag:
                        return True
            
        
        return False
        
       
        