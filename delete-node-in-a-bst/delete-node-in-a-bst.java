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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        
        if(root.val > key)
        {
            root.left = deleteNode(root.left,key);
            return root;
        }
        else if(root.val < key)
        {
            root.right = deleteNode(root.right,key);
            return root;
        }
        else
        {
            if(root.left == null) return root.right;
            else if(root.right == null) return root.left;
            else
            {
                TreeNode node = root.right;
                while(node.left != null) node = node.left;
                int rightMin = node.val;
                root.val = rightMin;
                root.right = deleteNode(root.right,rightMin);
                
                return root;
            }
        }
    }
}









