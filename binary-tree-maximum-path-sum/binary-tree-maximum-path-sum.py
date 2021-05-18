# Definition for a binary tree node.
# class TreeNode:
#     def _init_(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = -9999999
    def maxPathSum(self, root: TreeNode) -> int:
        Solution.ans = -99999999
        Solution.util(root)
        return Solution.ans;
    def util(root):
        if root == None:
            return 0
        l = Solution.util(root.left)
        r = Solution.util(root.right)
        nodeMax = max(root.val,root.val+l+r,root.val + l,root.val + r)
        Solution.ans = max(Solution.ans,nodeMax)
        singleSum = max(root.val,root.val+l,root.val+r)
        return singleSum