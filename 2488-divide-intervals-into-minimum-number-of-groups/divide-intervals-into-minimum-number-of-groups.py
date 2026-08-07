class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        mpp=defaultdict(int)
        for l,r in intervals:
            mpp[l]+=1
            mpp[r+1]-=1
        mx=-float("inf")
        pref=0
        for el in sorted(mpp):
            pref+=mpp[el]
            mx=max(mx,pref)
        
            
        return mx

        