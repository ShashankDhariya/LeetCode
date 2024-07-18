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
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<TreeNode*> isLeaf;
    void getParent(TreeNode* root){
        if(!root->left && !root->right)
            isLeaf.push_back(root);

        if(root->left){
            parent[root->left] = root;
            getParent(root->left);
        }

        if(root->right){
            parent[root->right] = root;
            getParent(root->right);
        }
    }

    int traverse(TreeNode*& leaf, TreeNode* root, unordered_map<TreeNode*, bool>& vis, int& dist){
        if(!root || vis[root] || dist < 0)
            return 0;

        if(root != leaf && !root->left && !root->right)
            return 1;

        int ans = 0;
        vis[root] = 1;
        dist -= 1;
        ans += traverse(leaf, root->left, vis, dist);
        ans += traverse(leaf, root->right, vis, dist);
        ans += traverse(leaf, parent[root], vis, dist);
        vis[root] = 0;
        dist += 1;

        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        getParent(root);

        int ans = 0;
        unordered_map<TreeNode*, bool> vis;
        for(auto leaf: isLeaf)
            ans += traverse(leaf, leaf, vis, distance);
        
        return ans / 2; 
    }
};
