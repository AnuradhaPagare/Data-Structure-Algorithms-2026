/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> inorder_map;
    int post_idx;

    TreeNode* helper(int in_start, int in_end, vector<int>& postorder) {
        if (in_start > in_end) {
            return nullptr;
        }

        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        post_idx--;

        int root_in_idx = inorder_map[root_val];

        root->right = helper(root_in_idx + 1, in_end, postorder);
        root->left = helper(in_start, root_in_idx - 1, postorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        post_idx = postorder.size() - 1;
        
        return helper(0, inorder.size() - 1, postorder);
    }
};
