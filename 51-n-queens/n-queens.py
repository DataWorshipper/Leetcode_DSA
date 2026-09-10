class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        grid = [['.'] * n for _ in range(n)]
        ans=[]
        def check(grid):
            queen=[]
            for i in range(n):
                for j in range(n):
                    if grid[i][j]=='Q':
                        queen.append((i,j))
            flag=True
            for i in range(len(queen)):
                for j in range(i+1,len(queen)):
                    if queen[i][0]==queen[j][0] or queen[i][1]==queen[j][1] or abs(queen[i][1]-queen[j][1])==abs(queen[i][0]-queen[j][0]):
                        flag=False
                        break
            return flag
                

        def rec(row):
            nonlocal grid
            nonlocal ans
            if row==n:
                if check(grid):
                    ans.append(["".join(row) for row in grid])
                    return
            
            for col in range(n):
                grid[row][col]="Q"
                if check(grid):
                    rec(row+1)
              
                grid[row][col]="."
        
        rec(0)
        return ans



        