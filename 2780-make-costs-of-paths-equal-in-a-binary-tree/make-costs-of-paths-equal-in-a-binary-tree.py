class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans=0
        def dfs(node):
            nonlocal ans
            if node>n:
                return 0
            left=dfs(2*node)
            right=dfs(2*node+1)
            ans+=abs(left-right)
            return cost[node-1]+max(left,right)
        dfs(1)
        return ans

        