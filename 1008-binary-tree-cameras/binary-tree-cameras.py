# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        dp=defaultdict(int)
        def f(node,placecam,parentcam):
            if node is None:
                if placecam:
                    return 10**9
                return 0
            if node.left is None and node.right is None:
                if placecam:
                    return 1
                return 0 if parentcam else 10**9
            if (node,placecam,parentcam) in dp:
                return dp[(node,placecam,parentcam)]
            ans=0
            if placecam==1:
                ans=1+min(f(node.right,1,1),f(node.right,0,1)) +min(f(node.left,1,1),f(node.left,0,1))
            else:
                if parentcam==1:
                    ans=min(f(node.right,1,0),f(node.right,0,0))+min(f(node.left,1,0),f(node.left,0,0))
                else:
                    l1=f(node.right,1,0)+min(f(node.left,1,0),f(node.left,0,0))
                    r1=f(node.left,1,0)+min(f(node.right,1,0),f(node.right,0,0))
                    ans=min(l1,r1)
            dp[(node, placecam, parentcam)] = ans
            return ans

        
        return min(f(root,1,0),f(root,0,0))





        