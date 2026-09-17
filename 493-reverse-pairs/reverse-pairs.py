from sortedcontainers import SortedList
class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        s=SortedList()
        n=len(nums)
        s.add(nums[0])
        cnt=0
        for i in range(1,n):
            number=len(s)-s.bisect_right(2*nums[i])
            cnt+=number
            s.add(nums[i])
        return cnt

        