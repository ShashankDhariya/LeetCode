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

    bool LCA(TreeNode* root, int& startVal, int& destVal, TreeNode*& lca){
        if(lca)
            return 1;

        if(!root)
            return 0;

        bool left = LCA(root->left, startVal, destVal, lca);
        bool right = LCA(root->right, startVal, destVal, lca);

        if(lca)
            return 1;

        if(left && right)
            lca = root;

        if(startVal == root->val || destVal == root->val){
            if(left || right)
                lca = root;
            else 
                return 1;
        }
            
        return (left || right)? 1: 0;
    }

    bool traverse(TreeNode* root, int& val, string& str){
        if(!root)
            return 0;

        if(root->val == val)
            return 1;

        str += "L";
        if(traverse(root->left, val, str))
            return 1;
        str.pop_back();

        str += "R";
        if(traverse(root->right, val, str))
            return 1;
        str.pop_back();

        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = NULL;
        LCA(root, startValue, destValue, lca);

        string str1 = "";
        traverse(lca, startValue, str1);
        string str2 = "";
        traverse(lca, destValue, str2);

        for(auto& c: str1)
            c = 'U';
            
        return str1 + str2;
    }
};
