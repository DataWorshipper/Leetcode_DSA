class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:

        dp=dict()

        def f(index:int,prev:int,blocks:int):

            if blocks>target:
                return float('inf')

            if index==m:
                if blocks==target:
                    return 0
                else:
                    return float('inf')

            if (index,prev,blocks) in dp:
                return dp[(index,prev,blocks)]

            ans=float('inf')

            if houses[index]!=0:

                color=houses[index]

                if prev==-1:
                    ans=min(ans,f(index+1,color,1))

                elif color==prev:
                    ans=min(ans,f(index+1,color,blocks))

                else:
                    ans=min(ans,f(index+1,color,blocks+1))

            else:

                for i in range(n):

                    color=i+1

                    if prev==-1:
                        ans=min(ans,
                                f(index+1,color,1)+cost[index][i])

                    elif color==prev:
                        ans=min(ans,
                                f(index+1,color,blocks)+cost[index][i])

                    else:
                        ans=min(ans,
                                f(index+1,color,blocks+1)+cost[index][i])

            dp[(index,prev,blocks)]=ans
            return ans

        ans=f(0,-1,0)

        if ans==float('inf'):
            return -1

        return ans