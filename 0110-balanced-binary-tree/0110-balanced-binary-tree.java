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
    public boolean isBalanced(TreeNode root) {
        // If the helper returns -1, it means the tree is unbalanced.
        return checkHeight(root) != -1;
    }

    private int checkHeight(TreeNode node) {
        // Base case: An empty tree has a height of 0.
        if (node == null) {
            return 0;
        }

        // Check the height of the left subtree
        int leftHeight = checkHeight(node.left);
        if (leftHeight == -1) return -1; // Left subtree is already unbalanced

        // Check the height of the right subtree
        int rightHeight = checkHeight(node.right);
        if (rightHeight == -1) return -1; // Right subtree is already unbalanced

        // If the current node is unbalanced, return -1
        if (Math.abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Otherwise, return the actual height of this current node's subtree
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
