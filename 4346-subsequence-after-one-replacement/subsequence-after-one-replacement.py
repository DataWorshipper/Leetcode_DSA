class Solution:
    def canMakeSubsequence(self, s: str, t: str) -> bool:
        n=len(s)
        m=len(t)
        if n>m:
            return False
        if n==1:
            return True
        i=0
        j=0
        pref=[-1]*n
        suff=[-1]*n
        while i<n and j<m:
            if s[i]==t[j]:
                pref[i]=j
                i+=1
            j+=1
        i=n-1
        j=m-1
        while i>=0 and j>=0:
            if s[i]==t[j]:
                suff[i]=j
                i-=1
            j-=1
        
        if pref[n-1]!=-1:
            return True
        
        if suff[1]!=-1 and suff[1]>0:
            return True
        if pref[n-2]!=-1 and pref[n-2]<m-1:
            return True
        for i in range(1,n-1):
            if pref[i-1]!=-1 and suff[i+1]!=-1 and pref[i-1]+1<suff[i+1]:
                return True
        return False
        
            

        