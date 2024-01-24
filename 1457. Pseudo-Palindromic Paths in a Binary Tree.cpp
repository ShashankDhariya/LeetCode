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
    int traverse(TreeNode* root, int freq){
        if(!root)
            return 0;

        if(freq & (1 << root->val))
            freq ^= (1 << root->val);
        else 
            freq |= (1 << root->val);

        if(!root->left && !root->right)
            return __builtin_popcount(freq) < 2;

        int left = traverse(root->left, freq);
        int right = traverse(root->right, freq);

        return left + right;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        return traverse(root, 0);
    }
};
