class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        mpp=defaultdict(int)
        for number,start,end in trips:
            mpp[start]+=number
            mpp[end]-=number
        pref=[0]*1002
        pref[0]=mpp[0]
        for i in range(len(pref)):
            pref[i]=pref[i-1]+mpp[i]
        for i in range(len(pref)):
            if pref[i]>capacity:
                return False
        return True
        