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

    void traverse(TreeNode* root, string str, vector<string>& res){
        if(!root)
            return;

        str += 'a' + root->val;
        if(!root->left && !root->right)
            res.push_back(str);

        traverse(root->left, str, res);
        traverse(root->right, str, res);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        traverse(root, "", res);

        for(auto& str: res)
            reverse(str.begin(), str.end());

        sort(res.begin(), res.end());
        return res[0];
    }
};
