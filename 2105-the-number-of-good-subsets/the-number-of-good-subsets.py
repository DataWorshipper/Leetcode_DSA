class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        cnt=defaultdict(int)
        for val in nums:
            cnt[val]+=1
        
        arr=[2,3,5,7,11,13,17,19,23,29]
        mpp=defaultdict(int)
        for i,val in enumerate(arr):
            mpp[val]=i
        MOD=10**9+7
        msk=defaultdict(int)
        def binexp(k):
            if k==0:
                return 1
            if k==1:
                return 2
            
            half=(binexp(k//2))%MOD
            if k%2==0:
                return ((half%MOD)*(half%MOD))%MOD
            else:
                return ((half%MOD)*(half%MOD)*2)%MOD
        
           
        def mask(val:int):
            curr_mask=0
            x=val
            flag=True
            for prime in arr:
                p=prime
                cnt=0
                while val%p==0:
                    cnt+=1
                    val//=p
                    
                if cnt==1:
                    idx=mpp[p]
                    curr_mask|=(1<<idx)
                elif cnt>1:
                    msk[x]=-1
                    flag=False
                    break
            if flag==True:
                msk[x]=curr_mask
        dp=defaultdict(int)
        cnt_one=0
        for val in nums:
            mask(val)
            if val==1:
                cnt_one+=1
        
        def f(val,mask):
            if val==31:
                return mask>0
            if (val,mask) in dp:
                return dp[(val,mask)]
            ans=f(val+1,mask)%MOD
            if cnt[val]!=0 and msk[val]!=-1:
                overlap=mask&msk[val]
                if overlap==0:
                    new_msk=mask|msk[val]
                    ans=(ans+(cnt[val]*f(val+1,new_msk))%MOD)%MOD
            
            dp[(val,mask)]=ans%MOD
            return ans%MOD
        ans=f(2,0)%MOD
        subset_one=binexp(cnt_one)%MOD
        return (ans*subset_one)%MOD





            
            

        

        





        