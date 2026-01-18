class Solution:
    def minDays(self, a, m, k):
        if m * k > len(a):
            return -1

        low = min(a)
        high = max(a)
        ans = -1

        while low <= high:
            mid = (low + high) // 2
            consec = 0
            bouq = 0

            for x in a:
                if x <= mid:
                    consec += 1
                    if consec == k:
                        bouq += 1
                        consec = 0
                else:
                    consec = 0

            if bouq >= m:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans


#__import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0"))
