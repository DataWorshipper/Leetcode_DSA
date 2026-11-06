class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        arr=[]
        for el in start:
            arr.append((el,el+d))
        arr.sort()
        def check(diff):
            vis=[0]*len(start)
            vis[0]=1
            st=arr[0][0]
            flag=True
            for i in range(1,len(start)):
                if arr[i][0]-st>=diff:
                    vis[i]=1
                    st=arr[i][0]
                    continue
                    
                else:
                    diff1=diff-(arr[i][0]-st)
                    if arr[i][0]+diff1<=arr[i][1]:
                        vis[i]=1
                        st=arr[i][0]+diff1
                        continue
                        
                    else:
                        flag=False
                        break
            return flag
        low=0
        mn = min(x[0] for x in arr)
        mx = max(x[1] for x in arr)     
        high=mx-mn+1
        ans=0
        while low<=high:
            mid=low+(high-low)//2
            if check(mid):
                ans=mid
                low=mid+1
            else:
                high=mid-1
        return ans

        