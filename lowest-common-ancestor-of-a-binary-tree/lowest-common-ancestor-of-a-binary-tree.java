/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        if(root == null) return null;
        if(A.val == root.val && B.val == root.val) return root;

        if(A.val == root.val) return root;
        if(B.val == root.val) return root;

        TreeNode leftAns = lowestCommonAncestor(root.left,A,B);
        TreeNode rightAns = lowestCommonAncestor(root.right,A,B);

        if(leftAns != null && rightAns != null) return root;
        else if(leftAns != null) return leftAns;
        else return rightAns;
    }
}