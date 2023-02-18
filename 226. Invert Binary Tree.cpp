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

    TreeNode* traverse(TreeNode* root){
        if(!root)
            return NULL;

        TreeNode* left = traverse(root->left);
        TreeNode* right = traverse(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
};
