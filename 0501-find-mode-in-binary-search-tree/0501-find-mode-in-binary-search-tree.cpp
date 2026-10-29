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
    TreeNode* prev = nullptr;
    int current_count = 0;
    int max_count = 0;
    vector<int> modes;

    void inOrder(TreeNode* root, bool modes_pass) {
        if (!root) return;

        inOrder(root->left, modes_pass);

        if (prev && prev->val == root->val) {
            current_count++;
        } else {
            current_count = 1;
        }

        if (!modes_pass) {
            max_count = max(max_count, current_count);
        } else {
            if (current_count == max_count) {
                modes.push_back(root->val);
            }
        }

        prev = root;

        inOrder(root->right, modes_pass);
    }

public:
    vector<int> findMode(TreeNode* root) {
        current_count = 0;
        max_count = 0;
        prev = nullptr;
        inOrder(root, false);

        current_count = 0;
        prev = nullptr;
        inOrder(root, true);

        return modes;
    }
};
