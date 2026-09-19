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
    int diameter = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        height(root);
        return diameter;        
    }
    public int height(TreeNode node){
        
        if(node == null){
            return 0;
        }

        int leftN = height(node.left);
        int rightN = height(node.right);

        diameter = Math.max(diameter, leftN + rightN);

        return 1 + Math.max(leftN, rightN);
    }
}