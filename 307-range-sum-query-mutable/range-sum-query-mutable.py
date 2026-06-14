class NumArray:

    def __init__(self, nums: List[int]):
        self.n=len(nums)
        self.bit=[0]*(self.n+1)
        self.nums=nums
        for i in range(self.n):
            idx=i+1
            while idx<=self.n:
                self.bit[idx]+=self.nums[i]
                idx+=(idx&-idx)
        
        

    def update(self, index: int, val: int) -> None:
        diff=val-self.nums[index]
        id=index+1
        self.nums[index]=val
        while id<=self.n:
            self.bit[id]+=diff
            id+=(id&-id)
        
    def query(self,index)->int:
        idx=index+1
        ans=0
        while idx>0:
            ans+=self.bit[idx]
            idx-=(idx&-idx)
        return ans
             

    def sumRange(self, left: int, right: int) -> int:
        if left==0:
            return self.query(right)
        else:
            return self.query(right)-self.query(left-1)
        

        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)