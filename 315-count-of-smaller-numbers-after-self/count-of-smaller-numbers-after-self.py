from sortedcontainers import SortedList
class Solution:
    def countSmaller(self, nums: list[int]) -> list[int]:
        n=len(nums)
        s=SortedList()
        s.add(nums[-1])
        cnt=[0]*n
        for i in range(n-2,-1,-1):
            cnt[i]=s.bisect_left(nums[i])
            s.add(nums[i])
        return cnt

        