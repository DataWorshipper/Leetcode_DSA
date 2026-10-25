

class Solution:
    def countDistinct(self, nums: list[int], k: int, p: int) -> int:
        n = len(nums)

        nums1 = nums.copy()
        for i in range(n):
            if nums1[i] % p == 0:
                nums1[i] = 0

        MOD1 = 10**9 + 7
        MOD2 = 10**9 + 9
        base = 911382323

        power1 = [1] * (n + 1)
        power2 = [1] * (n + 1)
        pref1 = [0] * (n + 1)
        pref2 = [0] * (n + 1)

        for i in range(n):
            pref1[i + 1] = (pref1[i] * base + nums[i]) % MOD1
            pref2[i + 1] = (pref2[i] * base + nums[i]) % MOD2

            power1[i + 1] = (power1[i] * base) % MOD1
            power2[i + 1] = (power2[i] * base) % MOD2

        def gethash(l, r, pref, power, MOD):
            return (pref[r + 1] - pref[l] * power[r - l + 1]) % MOD

        l = 0
        mpp = defaultdict(int)
        seen = set()

        for r in range(n):
            mpp[nums1[r]] += 1

            while mpp[0] > k:
                mpp[nums1[l]] -= 1
                if mpp[nums1[l]] == 0:
                    del mpp[nums1[l]]
                l += 1

            for i in range(l, r + 1):
                h1 = gethash(i, r, pref1, power1, MOD1)
                h2 = gethash(i, r, pref2, power2, MOD2)
                seen.add((h1, h2, r - i + 1))

        return len(seen)