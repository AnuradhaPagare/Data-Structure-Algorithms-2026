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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list1 = new LinkedList<>();

        if(root == null){
            return list1;
        }

        Queue<TreeNode> q = new LinkedList<>();
        Deque<List<Integer>> stack = new ArrayDeque<>();
        

        q.add(root);

        while(!q.isEmpty()){
            int levelSize = q.size();
            List<Integer> list2 = new LinkedList<>();

            for(int i = 0; i < levelSize; i++){
                TreeNode curr = q.poll();
                list2.add(curr.val);

                if(curr.left != null){
                    q.add(curr.left);
                }
                if(curr.right != null){
                    q.add(curr.right);
                }

            }
            stack.push(list2);

        }
        while(!stack.isEmpty()){
            list1.add(stack.pop());
        }
            
        return list1;
        
    }
}