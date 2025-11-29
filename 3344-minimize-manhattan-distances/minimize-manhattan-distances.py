class Solution(object):
    def f1(self, points):
        a = [0] * len(points)
        for i in range(len(points)):
            x = points[i][0]
            y = points[i][1]
            a[i] = x + y
        return a

    def f2(self, points):
        a = [0] * len(points)
        for i in range(len(points)):
            x = points[i][0]
            y = points[i][1]
            a[i] = x - y
        return a

    def ans(self, s, d, idx):
        s = s[:idx] + s[idx+1:]
        d = d[:idx] + d[idx+1:]
        s.sort()
        d.sort()
        if not s:
            return 0
        a = s[-1] - s[0]
        b = d[-1] - d[0]
        return max(a, b)

    def minimumDistance(self, points):
        n = len(points)
        maxsum = -10**30
        minsum = 10**30
        maxdiff = -10**30
        mindiff = 10**30
        maxsumidx = minsumidx = maxdiffidx = mindiffidx = 0

        for i in range(n):
            x = points[i][0]
            y = points[i][1]
            s = x + y
            d = x - y
            if s > maxsum:
                maxsum = s
                maxsumidx = i
            if s < minsum:
                minsum = s
                minsumidx = i
            if d > maxdiff:
                maxdiff = d
                maxdiffidx = i
            if d < mindiff:
                mindiff = d
                mindiffidx = i

        s = self.f1(points)
        d = self.f2(points)

        a1 = self.ans(s, d, maxsumidx)
        a2 = self.ans(s, d, minsumidx)
        a3 = self.ans(s, d, maxdiffidx)
        a4 = self.ans(s, d, mindiffidx)

        s_sorted = sorted(s)
        d_sorted = sorted(d)
        a5 = max(s_sorted[-1] - s_sorted[0], d_sorted[-1] - d_sorted[0])

        return min(a1, a2, a3, a4, a5)
