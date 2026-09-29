class Solution:
    spf = None

    @staticmethod
    def get_spf():
        if Solution.spf is not None:
            return Solution.spf

        N = 10**6 + 1
        spf = list(range(N))

        for i in range(2, int(N**0.5) + 1):
            if spf[i] == i:  # i is prime
                for j in range(i * i, N, i):
                    if spf[j] == j:
                        spf[j] = i

        Solution.spf = spf
        return spf

    def minJumps(self, nums: List[int]) -> int:
        spf = Solution.get_spf()

        mpp = defaultdict(list)

        def factorize(x, idx):
            while x > 1:
                p = spf[x]
                mpp[p].append(idx)

                while x % p == 0:
                    x //= p

        for i, x in enumerate(nums):
            factorize(x, i)

        sz = len(nums)

        q = deque([(0, 0)])
        vis = {0}
        used_prime = set()

        while q:
            idx, steps = q.popleft()

            if idx == sz - 1:
                return steps

            if idx - 1 >= 0 and idx - 1 not in vis:
                vis.add(idx - 1)
                q.append((idx - 1, steps + 1))

            if idx + 1 < sz and idx + 1 not in vis:
                vis.add(idx + 1)
                q.append((idx + 1, steps + 1))

        
            if spf[nums[idx]] == nums[idx]:
                p = nums[idx]

                if p not in used_prime:
                    used_prime.add(p)

                    for n_idx in mpp[p]:
                        if n_idx not in vis:
                            vis.add(n_idx)
                            q.append((n_idx, steps + 1))

        return -1