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
    unordered_map<int, vector<int>> mapping;
    void findParent(TreeNode* root){
        if(root->left){
            findParent(root->left);
            mapping[root->left->val].push_back(root->val);
            mapping[root->val].push_back(root->left->val);
        }

        if(root->right){
            findParent(root->right);
            mapping[root->right->val].push_back(root->val);
            mapping[root->val].push_back(root->right->val);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        findParent(root);

        int ans = 0;
        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto list = mapping[q.front()];
                q.pop();
                int size = list.size();

                for(int i=0;i<size;i++){
                    if(!vis[list[i]]){
                        vis[list[i]] = 1;
                        q.push(list[i]);
                    }
                }
            }

            ans++;
        }

        return ans-1;
    }
};
