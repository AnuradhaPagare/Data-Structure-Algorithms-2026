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
    public int maxLevelSum(TreeNode root) {
        if(root == null){
            return 0;
        }
        int level = 1;
        int maxSum = Integer.MIN_VALUE;
        int currLevel = 1;
        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        while(!q.isEmpty()){

            int QueSize = q.size();
            int sum = 0;


            for(int i = 0; i < QueSize; i++){
                TreeNode curr = q.poll();
                sum += curr.val;              
                      
                if(curr.left != null)
                    q.add(curr.left);

                if(curr.right != null)
                    q.add(curr.right);   
            }

            if(maxSum < sum){
                maxSum = sum;
                level = currLevel;
            } 
            currLevel++;
            
        }

        return level;
    }
}