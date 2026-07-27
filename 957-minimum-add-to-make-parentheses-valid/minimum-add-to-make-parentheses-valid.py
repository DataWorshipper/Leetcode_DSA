class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        b=0
        cnt=0
        for c in s:
            if c=='(':
                b+=1
            else:
                b-=1
            if b<0:
                cnt+=1
                b=0
        return abs(b)+abs(cnt)
        