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
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> path;
        if(root == nullptr){
            return path;
        }

        dfs(root, "", path);
        return path;
    }
    private:
    void dfs(TreeNode* node, string currPath, vector<string>& path){

        currPath += to_string(node->val);

        if(node->left == nullptr && node->right == nullptr){
            path.push_back(currPath);
            return;
        }

        if(node->left != nullptr){
            dfs(node->left, currPath + "->", path);
        }

        if(node->right != nullptr){
            dfs(node->right, currPath + "->", path);
        }
    }
};