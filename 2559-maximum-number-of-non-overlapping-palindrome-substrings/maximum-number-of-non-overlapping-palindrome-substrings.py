class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        st=set()
        n=len(s)
        for i in range(n):
            c=0
            while i-c>=0 and i+c<n and s[i-c]==s[i+c]:
                if 2*c+1>=k:
                    st.add((i-c,i+c))
                c+=1
            l=i
            r=i-1
            while l>=0 and r<n and s[l]==s[r]:
                if r-l+1>=k:
                    st.add((l,r))
                l-=1
                r+=1
        dp=[0]*n
        for i in range(n):
            if i > 0:
                dp[i] = dp[i-1]
            if (0, i) in st:
                dp[i] = max(dp[i], 1)
            for j in range(i):
                if (j+1,i) in st:
                    dp[i]=max(dp[i],dp[j]+1)

        return dp[n-1]

        