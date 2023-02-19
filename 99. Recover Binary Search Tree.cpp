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

    void traverse(TreeNode* root, vector<TreeNode*>& res){
        if(!root)
            return;
        
        traverse(root->left, res);
        res.push_back(root);
        traverse(root->right, res);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> res;
        traverse(root, res);

        TreeNode* a = NULL;
        TreeNode* b = NULL;
        int n = res.size();
        for(int i=1;i<n;i++){
            if(res[i-1]->val > res[i]->val){
                if(!a)
                    a = res[i-1];
                b = res[i];
            }
        }
        int num = a->val;
        a->val = b->val;
        b->val = num;
    }
};
