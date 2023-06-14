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

    void traversal(TreeNode* root, int& prev, int& ans){
        if(!root)
            return;
        traversal(root->left, prev, ans);
        if(prev != -1)
            ans = min(ans, root->val-prev);
        prev = root->val;
        traversal(root->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        traversal(root, prev, ans);
        return ans;
    }
};
