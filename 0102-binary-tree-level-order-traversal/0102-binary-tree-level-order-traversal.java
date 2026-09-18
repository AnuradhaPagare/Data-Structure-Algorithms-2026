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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> list1 = new ArrayList<>();
        //int level = 0;
        if(root == null){
            return list1;
        }
        q.add(root);
        while(!q.isEmpty()){
            
            int levelSize = q.size();
            List<Integer> list2 = new ArrayList<>();

            for(int i = 0; i < levelSize; i++){
                TreeNode curr = q.poll();
                list2.add(curr.val);
                if(curr.left != null)
                    q.add(curr.left);
                
                if(curr.right != null)
                    q.add(curr.right);
            }
            list1.add(list2);
        }
        return list1;
        
    }
}