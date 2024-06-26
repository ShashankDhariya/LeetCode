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

    void traverse(TreeNode* root, vector<int>& inorder){
        if(!root)
            return;

        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }

    TreeNode* makeTree(int left, int right, vector<int>& inorder){
        if(left > right)
            return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(inorder[mid]);
        
        node->left = makeTree(left, mid - 1, inorder);
        node->right = makeTree(mid + 1, right, inorder);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        traverse(root, inorder);

        return makeTree(0, inorder.size() - 1, inorder);
    }
};
