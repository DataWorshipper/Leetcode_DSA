class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
            cnt = Counter(nums)

            pq = [-x for x in cnt.values()]
            heapq.heapify(pq)

            while len(pq) >= 2:
                a = -heapq.heappop(pq)
                b = -heapq.heappop(pq)

                a -= 1
                b -= 1

                if a:
                    heapq.heappush(pq, -a)
                if b:
                    heapq.heappush(pq, -b)

            return -pq[0] if pq else 0
                    