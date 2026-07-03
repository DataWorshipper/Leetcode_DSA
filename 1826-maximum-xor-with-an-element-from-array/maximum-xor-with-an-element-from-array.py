class TrieNode():
        def __init__(self):
            self.child=[None]*2
class Trie():
        def __init__(self):
            self.root=TrieNode()
        def insert(self,num):
            node=self.root
            for i in range(31,-1,-1):
                bit=(num>>i)&1
                if node.child[bit]==None:
                    node.child[bit]=TrieNode()
                
                node=node.child[bit]
        
        def maxxor(self,num):
            node=self.root
            ans=0
            for i in range(31,-1,-1):
                bit=(num>>i)&1
                if node.child[1-bit]!=None:
                    node=node.child[1-bit]
                    ans+=(1<<i)
                else:
                    node=node.child[bit]

            return  ans
class Solution:     
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        arr=[]
        for i in range(len(queries)):
             x,m=queries[i][0],queries[i][1]
             arr.append((x,m,i))
        

        arr.sort(key=lambda x:x[1])
        nums.sort()
        ans=[0]*len(arr)
        t=Trie()
        last=0
        for j in range(len(arr)):
            x,m,i=arr[j][0],arr[j][1],arr[j][2]
            idx=bisect.bisect_right(nums,m)
            if idx==0:
                ans[i]=-1
            else:
                
                for k in range(last,idx):
                    t.insert(nums[k])
                ans[i]=t.maxxor(x)
                last=idx
        
        return ans
            
                


            

            


        