class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mpp = defaultdict(list)

        MOD1 = 10**9 + 7
        MOD2 = 10**9 + 9
        B = 1000003

        for i, s in enumerate(strs):
            cnt = [0] * 26

            for ch in s:
                cnt[ord(ch) - ord('a')] += 1

            h1 = h2 = 0

            for x in cnt:
                h1 = (h1 * B + x) % MOD1
                h2 = (h2 * B + x) % MOD2

            mpp[(h1, h2)].append(i)

        ans = []

        for key in mpp:
            ans.append([strs[i] for i in mpp[key]])

        return ans