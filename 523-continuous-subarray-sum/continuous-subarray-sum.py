class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:

        n = len(nums)

        pref = [0] * n
        pref[0] = nums[0]

        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]

        first = {}

        for i in range(n):

            rem = pref[i] % k

            if rem == 0 and i >= 1:
                return True

            if rem in first:

                if i - first[rem] >= 2:
                    return True

            else:
                first[rem] = i

        return False