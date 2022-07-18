# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        
        
        
        def dfs(i,j):
            if i>j:
                return [None]
            arr = []
            for x in range(i,j+1):
                left = dfs(i,x-1);
                right = dfs(x+1,j)
                
                for l in left:
                    for r in right:
                        root = TreeNode(x)
                        root.left , root.right = l,r
                        arr.append(root)
            return arr
        
        return dfs(1,n);