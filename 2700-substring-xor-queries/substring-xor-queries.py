class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        n = len(s)
        mpp = {}

        def getval(t):
            x = 0
            for ch in t:
                x = x * 2 + int(ch)
            return x

        def process(l):
            for i in range(n - l + 1):
                t = s[i:i+l]
                x = getval(t)

                if x not in mpp or l < mpp[x][0]:
                    mpp[x] = [l, i, i+l-1]

        for l in range(1, 31):
            process(l)

        ans = []

        for a, b in queries:
            x = a ^ b

            if x in mpp:
                ans.append(mpp[x][1:])
            else:
                ans.append([-1, -1])

        return ans