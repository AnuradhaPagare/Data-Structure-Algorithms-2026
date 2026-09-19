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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> list1 = new LinkedList<>();
        int level = 0;
        Queue<TreeNode> q = new LinkedList<>();

        if(root == null){
            return list1;
        }

        q.add(root);

        while(!q.isEmpty()){
            int QueSize = q.size();
            List<Integer> list2 = new LinkedList<>();

            for(int i = 0; i < QueSize; i++){
                TreeNode curr = q.poll();

                list2.add(curr.val);

                if(curr.left != null){
                    q.add(curr.left);
                }

                if(curr.right != null){
                    q.add(curr.right);
                }
               
            }

            if(level % 2 == 1){
                Collections.reverse(list2);
            }

            list1.add(list2);
            level++;
        }

        return list1;     
        
    }
}