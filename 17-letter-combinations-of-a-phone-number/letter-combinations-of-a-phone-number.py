class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        mpp=defaultdict(list)
        mpp[2].append(['a','b','c'])
        mpp[3].append(['d','e','f'])
        mpp[4].append(['g','h','i'])
        mpp[5].append(['j','k','l'])
        mpp[6].append(['m','n','o'])
        mpp[7].append(['p','q','r','s'])
        mpp[8].append(['t','u','v'])
        mpp[9].append(['w','x','y','z'])
        ans=[]
        n=len(digits)
        def rec(index,s):
            nonlocal ans
            if index==n:
                ans.append(s)
                return
            ch=ord(digits[index])-ord('0')
            for vec in mpp[ch]:
                for i in range(len(vec)):
                    s+=vec[i]
                    rec(index+1,s)
                    s=s[:-1]
        rec(0,"")
        return ans
            


        