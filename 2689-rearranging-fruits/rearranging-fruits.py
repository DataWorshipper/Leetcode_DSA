class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        mpp1 = Counter(basket1)
        mpp2 = Counter(basket2)

        diff1 = mpp1 - mpp2
        diff2 = mpp2 - mpp1
        
        
       
        extra1 = []
        extra2 = []

        for k,v in diff1.items():
            if v % 2:
                return -1
            extra1.append([k, v//2])

        for k,v in diff2.items():
            if v % 2:
                return -1
            extra2.append([k, v//2])
        
        extra1.sort()
        extra2.sort(reverse=True)

        i=0
        j=0
        cost=0
        m = min(min(basket1), min(basket2))
        while i < len(extra1) and j < len(extra2):

            take = min(extra1[i][1], extra2[j][1])

            cost += take * min(
                min(extra1[i][0], extra2[j][0]),
                2 * m
            )

            extra1[i][1] -= take
            extra2[j][1] -= take

            if extra1[i][1] == 0:
                i += 1

            if extra2[j][1] == 0:
                j += 1
        return cost
            


        
        