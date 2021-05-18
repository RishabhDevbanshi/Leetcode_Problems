/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = Integer.MIN_VALUE;
    public int util(TreeNode root)
    {
        if(root == null) return 0;
        
        int l = util(root.left);
        int r = util(root.right);
        
        int nodeMax = Integer.max(Integer.max(root.val,root.val + l + r),
                          Integer.max(root.val + l,root.val + r));
        ans = Integer.max(ans,nodeMax);
        int singleSum = Integer.max(root.val,Integer.max(root.val + l,root.val + r));
        
        return singleSum;
        
    }
    
    public int maxPathSum(TreeNode root) {
        ans = Integer.MIN_VALUE;
        util(root);
        return ans;
    }
}














