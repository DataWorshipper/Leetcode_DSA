class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans=[]
        def rec(open,close,bal,s,index):
            nonlocal ans
            if index==2*n:
                if bal==0:
                    ans.append(s)
                return
            
            s+='('
            rec(open+1,close,bal+1,s,index+1)
            s=s[:-1]
            if open>close:
                s+=')'
                rec(open,close+1,bal-1,s,index+1)
        rec(0,0,0,"",0)
        return ans
            
        