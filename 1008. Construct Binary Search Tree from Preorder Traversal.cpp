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

    int split(int val, int start, int end, vector<int>& preorder){
        while(start<end && val >= preorder[start])
            start++;
        
        return start;
    }

    TreeNode* solution(int i, int j, vector<int>& preorder){
        if(i == j)
            return NULL;

        TreeNode* node = new TreeNode(preorder[i]);
        int idx = split(node->val, i, j, preorder);

        node->left = solution(i+1, idx, preorder);
        node->right = solution(idx, j, preorder);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solution(0, preorder.size(), preorder);
    }
};
