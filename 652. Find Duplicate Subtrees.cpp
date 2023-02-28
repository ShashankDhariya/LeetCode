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

    string traverse(TreeNode* root, unordered_map<string, int>& freq, vector<TreeNode*>& ans){
        if(!root)
            return "N";

        string left = traverse(root->left, freq, ans);
        string right = traverse(root->right, freq, ans);

        string str = to_string(root->val) + ',' + left + ',' + right;
        freq[str]++;
        if(freq[str] == 2)
            ans.push_back(root);

        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> freq;
        traverse(root, freq, ans);
        return ans;
    }
};
