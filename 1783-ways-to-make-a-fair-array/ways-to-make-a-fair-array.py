class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:

        n = len(nums)

        pref_even = [0] * n
        pref_odd = [0] * n

        pref_even[0] = nums[0]

        for i in range(1, n):

            pref_even[i] = pref_even[i - 1]
            pref_odd[i] = pref_odd[i - 1]

            if i % 2 == 0:
                pref_even[i] += nums[i]
            else:
                pref_odd[i] += nums[i]

        ans = 0

        for i in range(n):

            left_even = pref_even[i - 1] if i > 0 else 0
            left_odd = pref_odd[i - 1] if i > 0 else 0

            right_even = pref_even[n - 1] - pref_even[i]
            right_odd = pref_odd[n - 1] - pref_odd[i]

            new_even = left_even + right_odd
            new_odd = left_odd + right_even

            if new_even == new_odd:
                ans += 1

        return ans