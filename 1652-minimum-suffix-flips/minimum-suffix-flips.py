class Solution:
    def minFlips(self, target: str) -> int:
        n=len(target)
        ans=0
        prev='0'
        for i in range(n):
            if prev!=target[i]:
                ans+=1
                prev=target[i]
        return ans