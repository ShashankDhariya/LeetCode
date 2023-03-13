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

    int getNode(int& node, vector<int>& postorder, int s, int e){
        for(int i=s;i<=e;i++){
            if(postorder[i] == node)
                return i;
        }
        return -1;
    }

    TreeNode* traverse(int& pind, vector<int>& inorder, vector<int>& postorder, int s, int e){
        if(pind < 0 || s > e)
            return NULL;

        int node = postorder[pind--];
        int ind = getNode(node, inorder, s, e);

        TreeNode* root = new TreeNode(node);
        root->right = traverse(pind, inorder, postorder, ind+1, e);
        root->left = traverse(pind, inorder, postorder, s, ind-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int pind = n-1;
        return traverse(pind, inorder, postorder, 0, n-1);
    }
};
