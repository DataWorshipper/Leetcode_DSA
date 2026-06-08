class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:

        def lis(arr):
            n = len(arr)
            dp = [1] * n

            for i in range(n):
                for j in range(i):
                    if arr[j] < arr[i]:
                        dp[i] = max(dp[i], 1 + dp[j])

            return dp

        def lds(arr):
            n = len(arr)
            dp = [1] * n

            for i in range(n - 1, -1, -1):
                for j in range(i + 1, n):
                    if arr[i] > arr[j]:
                        dp[i] = max(dp[i], 1 + dp[j])

            return dp

        inc = lis(nums)
        dec = lds(nums)

        n = len(nums)
        ans = n

        for i in range(n):
            if inc[i] > 1 and dec[i] > 1:
                ans = min(ans, n - (inc[i] + dec[i] - 1))

        return ans