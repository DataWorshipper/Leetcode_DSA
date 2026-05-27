

class Solution:
    def minMaxWeight(self, n: int, edges, threshold: int) -> int:

      
        arr = []

        for u, v, w in edges:
            arr.append([w, u, v])

        arr.sort()

        low = arr[0][0]
        high = arr[-1][0]

        def dfs(adj, node, vis):

            vis[node] = 1

            for child in adj[node]:

                if vis[child] == 0:
                    dfs(adj, child, vis)

        ans = -1

        while low <= high:

            mid = low + (high - low) // 2

            idx = bisect.bisect_right(
                arr,
                [mid, float('inf'), float('inf')]
            )

            adj = defaultdict(list)

            for i in range(idx):

                w, u, v = arr[i]

                
                adj[v].append(u)

            vis = [0] * n

            dfs(adj, 0, vis)

            if all(vis):

                ans = mid
                high = mid - 1

            else:
                low = mid + 1

        return ans