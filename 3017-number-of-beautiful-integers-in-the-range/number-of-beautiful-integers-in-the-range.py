class Solution:
    def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        dp=defaultdict(int)
        def f(index,tight,valid,diff,rem,s):
            if index==len(s):
                if  valid ==1 and diff==0 and rem==0:
                    return 1
                else:
                    return 0
            
            if (index,tight,valid,diff,rem) in dp:
                return dp[(index,tight,valid,diff,rem)]
            ans=0
            limit=9 if tight==0 else int(s[index])
            for i in range(limit+1):
                newtight=0
                if tight==1 and i==int(s[index]):
                    newtight=1
                if valid==0:
                    if i==0:
                        ans+=f(index+1,newtight,0,diff,rem,s)
                    else:
                        newdiff=diff+1 if i%2==0 else diff-1
                        newrem=(rem*10+i)%k
                        ans+=f(index+1,newtight,1,newdiff,newrem,s)
                else:
                    newdiff=diff
                    if i%2==0:
                        newdiff+=1
                    else:
                        newdiff-=1
                    newrem=(rem*10+i)%k
                    ans+=f(index+1,newtight,1,newdiff,newrem,s)

            dp[(index,tight,valid,diff,rem)]=ans
            return ans
        
        s1=str(low-1)
        s2=str(high)
        dp.clear()
        a1=f(0,1,0,0,0,s2)
        dp.clear()
        a2=f(0,1,0,0,0,s1)
        if low>0:
            return a1-a2
        else:
             return  a1
        




                



        