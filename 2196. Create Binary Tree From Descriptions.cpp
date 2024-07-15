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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> exist;
        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* leaf = NULL;
        for(auto desc: descriptions){
            TreeNode* par = exist[desc[0]]? exist[desc[0]]: new TreeNode(desc[0]);
            TreeNode* child = exist[desc[1]]? exist[desc[1]]: new TreeNode(desc[1]);

            parent[par];
            parent[child] = par; 
            exist[desc[0]] = par;
            exist[desc[1]] = child;
            desc[2]? par->left = child: par->right = child;
        }

        for(auto& root: parent){
            if(!root.second)
                return root.first;
        }

        return NULL;
    }
};
