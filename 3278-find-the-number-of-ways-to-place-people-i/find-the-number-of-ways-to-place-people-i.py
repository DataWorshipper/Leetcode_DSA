class Solution:
    def numberOfPairs(self, points):
        n = len(points)

        def empty(A, B):
            x1, y1 = A
            x2, y2 = B

            xmin = min(x1, x2)
            xmax = max(x1, x2)
            ymin = min(y1, y2)
            ymax = max(y1, y2)

            for C in points:
                x, y = C

                if C == A or C == B:
                    continue

                if xmin <= x <= xmax and ymin <= y <= ymax:
                    return False

            return True

        ans = 0

        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]

                if ((x1 <= x2 and y1 >= y2) or
                    (x2 <= x1 and y2 >= y1)):

                    if empty(points[i], points[j]):
                        ans += 1

        return ans