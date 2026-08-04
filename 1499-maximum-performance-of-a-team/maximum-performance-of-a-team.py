class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        arr = []
        for i in range(n):
            arr.append((efficiency[i], speed[i]))

        arr.sort(reverse=True)

        pq = []          
        speed_sum = 0
        ans = 0
        MOD = 10**9 + 7

        for eff, spd in arr:
            heapq.heappush(pq, spd)
            speed_sum += spd

            if len(pq) > k:
                speed_sum -= heapq.heappop(pq)

            ans = max(ans, speed_sum * eff)

        return ans % MOD