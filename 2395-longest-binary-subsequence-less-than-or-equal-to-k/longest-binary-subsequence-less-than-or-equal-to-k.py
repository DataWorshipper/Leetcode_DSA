class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        length=1
        power=1
        
        n=len(s)
        s1=1 if s[n-1]=='1' else 0
        for i in range(n-2,-1,-1):
            if s[i]=='0':
                power*=2
                length+=1
            else:
                if s1+2*power<=k:
                    s1+=2*power
                    power=2*power
                    length+=1
                
        return length





        