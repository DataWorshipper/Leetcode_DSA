class Solution:
    def sumDecoded(self, nums: list[int]) -> int:
        MOD=10**9+7
        def binexp(a,b):
            if b==0:
                return 1
            if b==1:
                return a
            half=binexp(a,b//2)%MOD
            if b%2==0:
                return ((half)%MOD*(half%MOD))% MOD
            else:
                return ((half)%MOD*(half%MOD)*(a%MOD))%MOD
        

        def ind(num):
            width=num%10
            d=num//10
            s=str(d)
            x_s=s[:width]
            y_s=s[width:]
            x=int(x_s)
            y=int(y_s)
            return binexp(x,y)
        ans=0
        for val in nums:
            ans+=(ind(val))%MOD
        return ans%MOD


        