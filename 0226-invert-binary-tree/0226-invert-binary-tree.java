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
    public TreeNode invertTree(TreeNode root) {

        Queue<TreeNode> q = new LinkedList<>();

        if(root == null){
            return null;
        }

        q.add(root);
        while(!q.isEmpty()){
            int Qsize = q.size();

            for(int i = 0; i < Qsize; i++){
                TreeNode currNode = q.poll();
                
                // invert the node value
                TreeNode temp = currNode.left;
                currNode.left = currNode.right;
                currNode.right = temp;

                if(currNode.left != null){
                    q.add(currNode.left);
                }

                if(currNode.right != null){
                    q.add(currNode.right);
                }
            }
        }
        return root;        
    }
}