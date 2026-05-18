class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n=len(text)
        MOD1=10**9+7
        p=911382323
        pref=[0]*(n+1)
        power=[1]*(n+1)
        for i in range(n):
            val=ord(text[i])+1
            pref[i+1]=(pref[i]*p+val)%MOD1
            power[i+1]=(power[i]*p)%MOD1
        cnt=0
        for i in range(2,n+1,2):
            length=i
            l=0
            r=0
            mpp=defaultdict(int)
            while(r<n):
                if r-l+1==length:
                    mid=length//2
                    mid_i=l+(mid-1)
                    hash1=(pref[mid_i+1]-pref[l]*power[mid])%MOD1
                    hash2=(pref[r+1]-pref[mid_i+1]*power[mid])%MOD1
                    hash3=(pref[r+1]-pref[l]*power[length])%MOD1
                    if hash3 not in mpp:
                        if hash1==hash2:
                            cnt+=1
                        mpp[hash3]+=1
                    
                    l+=1
                
                r+=1
        return cnt



            

        