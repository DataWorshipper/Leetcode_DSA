class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        MOD=10**9+7
        a=pow(2,p)-2
        b=pow(2,p-1)-1
        c=pow(a,b,MOD)
        d=pow(2,p)-1
        return (c*d)%MOD
        