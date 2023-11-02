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

    pair<int, int> traverse(TreeNode* root, int& ans){
    if(!root)
        return {0, 0};

    auto left = traverse(root->left, ans);
    auto right = traverse(root->right, ans);
    
    int sum = root->val + left.first + right.first;
    int n = 1 + left.second + right.second;

    if(sum / n == root->val)
        ans++;

    return {sum, n};
}

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};
