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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        // Base case: If the current node is null, no path exists
        if (root == null) {
            return false;
        }
        
        // Check if we are at a leaf node
        if (root.left == null && root.right == null) {
            return root.val == targetSum;
        }
        
        // Subtract the current node's value from the target sum
        int remainingSum = targetSum - root.val;
        
        // Recursively check the left and right subtrees
        return hasPathSum(root.left, remainingSum) || hasPathSum(root.right, remainingSum);
    }
}
