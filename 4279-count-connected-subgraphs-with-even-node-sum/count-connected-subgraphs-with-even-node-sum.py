class Solution:
    def evenSumSubgraphs(self, nums: list[int], edges: list[list[int]]) -> int:
        class DSU:
            def __init__(self, n):
                self.parent = list(range(n))
                self.rank = [0] * n

            def find_parent(self, u):

                if u == self.parent[u]:
                    return u

                self.parent[u] = self.find_parent(self.parent[u])

                return self.parent[u]

            def unite(self, u, v):

                pu = self.find_parent(u)
                pv = self.find_parent(v)

                if pu == pv:
                    return

                ru = self.rank[pu]
                rv = self.rank[pv]

                if ru > rv:
                    self.parent[pv] = pu

                elif ru < rv:
                    self.parent[pu] = pv

                else:
                    self.parent[pv] = pu
                    self.rank[pu] += 1
        n=len(nums)
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        ans = 0

        for mask in range(1, 1 << n):

            dsu = DSU(n)

            s = 0

            for u in range(n):

                if (mask >> u) & 1:

                    s += nums[u]

                    for v in adj[u]:

                        if (mask >> v) & 1:

                            if dsu.find_parent(u) != dsu.find_parent(v):

                                dsu.unite(u, v)

            if s % 2:
                continue

            parents = set()

            for i in range(n):

                if (mask >> i) & 1:

                    parents.add(dsu.find_parent(i))

            if len(parents) == 1:

                ans += 1
        return ans