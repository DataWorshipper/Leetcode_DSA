class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        mpp = defaultdict(int)

        for x in arr:
            rem = (x % k + k) % k
            mpp[rem] += 1
        
        for x in arr:
            rem=(x%k+k)%k
            need=(k-rem)%k
            if need not in mpp:
                return False
            
            else:
                if rem!=need and mpp[rem]==mpp[need]:
                    continue
                elif rem==need and mpp[rem]%2==0:
                    continue
                else:
                    return False
        return True
        


        