class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        mp = []

        k = 0
        while 4 ** (k + 1) < 10**9:
            start = 4 ** k
            end = 4 ** (k + 1) - 1
            ops = k + 1
            mp.append((start, end, ops))
            k += 1

        
        mp.append((4 ** k, 10**9, k + 1))
        def get_bucket(x, mp):
            for i, (start, end, ops) in enumerate(mp):
                if start <= x <= end:
                    return i
            return -1
        def f(l, r, mp):
            L = get_bucket(l, mp)
            R = get_bucket(r, mp)

            total = 0

            if L == R:
                cnt = r - l + 1
                total += cnt * mp[L][2]
            else:
            
                start, end, ops = mp[L]
                cnt = end - l + 1
                total += cnt * ops

                
                for i in range(L + 1, R):
                    start, end, ops = mp[i]
                    cnt = end - start + 1
                    total += cnt * ops

            
                start, end, ops = mp[R]
                cnt = r - start + 1
                total += cnt * ops

            return (total + 1) // 2
        ans=0
        for l, r in queries:
            ans += f(l, r, mp)
        return ans
                