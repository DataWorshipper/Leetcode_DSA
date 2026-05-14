class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:

        n = len(nums)

        pref = [0] * n
        pref[0] = nums[0]

        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]

        mpp = defaultdict(int)

        ans = 0

        for x in pref:

            rem = ((x % k) + k) % k

            if rem == 0:
                ans += 1

            need = rem

            if need in mpp:
                ans += mpp[need]

            mpp[rem] += 1

        return ans
        