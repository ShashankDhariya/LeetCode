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

    void traverse(TreeNode* root, int& sum, TreeNode* node){
        if(root->right){
            node->right = new TreeNode(0);
            traverse(root->right, sum, node->right);
        }

        sum += root->val;
        node->val = sum;

        if(root->left){
            node->left = new TreeNode(0);
            traverse(root->left, sum, node->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        int sum = 0;
        traverse(root, sum, ans);
        return ans;
    }
};
