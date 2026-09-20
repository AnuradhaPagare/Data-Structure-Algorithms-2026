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
    public boolean isValidBST(TreeNode root) {
        // Use Long wrappers to handle the edge cases involving Integer.MIN_VALUE and Integer.MAX_VALUE
        return validate(root, null, null);
    }

    private boolean validate(TreeNode node, Integer min, Integer max) {
        // An empty tree is a valid BST
        if (node == null) {
            return true;
        }

        // The current node's value must fit strictly within the min and max bounds
        if ((min != null && node.val <= min) || (max != null && node.val >= max)) {
            return false;
        }

        // Recursively check the subtrees with updated bounds:
        // - Left child must be less than the current node's value (updates max bound)
        // - Right child must be greater than the current node's value (updates min bound)
        return validate(node.left, min, node.val) && validate(node.right, node.val, max);
    }
}
