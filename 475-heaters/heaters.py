class Solution:
    def findRadius(self, houses: list[int], heaters: list[int]) -> int:
        low=0
        n=len(houses)
        INF=float("inf")
        mx=-INF
        mn=INF
        houses.sort()
        for i in range(n):
            mx=max(mx,houses[i])
            mn=min(mx,houses[i])
        high=mx+mn
        def check(arr):
            arr.sort()
            i=0
            j=0
            while i<len(arr) and j<len(houses):
                while j<len(houses) and houses[j]>=arr[i][0] and houses[j]<=arr[i][1]:
                    j+=1
                
                i+=1
            return j==len(houses)
                
           
        ans=0
        while low<=high:
            mid=low+(high-low)//2
            arr=[]
            for i in range(len(heaters)):
                arr.append((heaters[i]-mid,heaters[i]+mid))
            if check(arr):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans

            

        