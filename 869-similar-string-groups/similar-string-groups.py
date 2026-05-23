from typing import List

class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        
        class DSU:
            def __init__(self, n):
                self.parent = list(range(n))
                self.rank = [0] * n

            def find_parent(self, u):
                if self.parent[u] == u:
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

        def similar(a, b):
            cnt = 0

            for i in range(len(a)):
                if a[i] != b[i]:
                    cnt += 1

            return cnt == 0 or cnt == 2

        n = len(strs)

        dsu = DSU(n)

        for i in range(n):
            for j in range(i + 1, n):

                if similar(strs[i], strs[j]):
                    dsu.unite(i, j)

        groups = set()

        for i in range(n):
            groups.add(dsu.find_parent(i))

        return len(groups)