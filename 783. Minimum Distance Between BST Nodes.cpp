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

    void traverse(TreeNode* root, int& prev, int& ans){
        if(!root)
            return;

        traverse(root->left, prev, ans);
        if(prev != -1)
            ans = min(ans, abs(prev - root->val));
        prev = root->val;
        traverse(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        traverse(root, prev, ans);
        return ans;
    }
};
