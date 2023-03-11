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

    int findIndex(int nodeVal, vector<int>& inorder, int n){
        for(int i=0;i<n;i++){
            if(nodeVal == inorder[i])
                return i;
        }
        return -1;
    }

    TreeNode* traverse(int& pind, vector<int>& preorder, vector<int>& inorder, int s, int e, int n){
        if(pind >= n || s > e)
            return NULL;

        int nodeVal = preorder[pind++];
        int ind = findIndex(nodeVal, inorder, n);

        TreeNode* root = new TreeNode(nodeVal);

        root->left = traverse(pind, preorder, inorder, s, ind-1, n);
        root->right = traverse(pind, preorder, inorder, ind+1, e, n);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int pind = 0;

        return traverse(pind, preorder, inorder, 0, n-1, n);
    }
};
