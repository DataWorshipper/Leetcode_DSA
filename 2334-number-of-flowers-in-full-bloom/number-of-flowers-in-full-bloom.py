class Solution:
    def fullBloomFlowers(self, flowers: list[list[int]], people: list[int]) -> list[int]:
        mpp=defaultdict(int)
        arr=[]
        for start,end in flowers:
            mpp[start]+=1
            mpp[end+1]-=1
            arr.append(start)
            arr.append(end+1)
        arr.sort()
        mpp2=defaultdict(int)
        pref=0
        ans=[]
        for k in sorted(mpp):
            pref+=mpp[k]
            mpp2[k]=pref
        for i in range(len(people)):
            ppl=people[i]
            low=0
            high=len(arr)-1
            cand=-1
            while low<=high:
                mid=low+(high-low)//2
                if arr[mid]<=ppl:
                    cand=mid
                    low=mid+1
                else:
                    high=mid-1
            if cand==-1:
                ans.append(0)
            else:
                ans.append(mpp2[arr[cand]])


        return ans
        
        