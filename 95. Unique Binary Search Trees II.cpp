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

    vector<TreeNode*> traverse(int s, int n){
        vector<TreeNode*> res;
        if(s > n){
            res.push_back(NULL);
            return res;
        }

        for(int i=s;i<=n;i++){
            vector<TreeNode*> left = traverse(s, i-1);
            vector<TreeNode*> right =  traverse(i+1, n);

            for(auto l: left){
                for(auto r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return traverse(1, n);
    }
};
