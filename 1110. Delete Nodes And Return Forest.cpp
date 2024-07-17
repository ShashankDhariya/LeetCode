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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> dlt;
        for(auto& td: to_delete)
            dlt[td] = 1;
        
        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> ans;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);

                    if(dlt[curr->left->val])
                        curr->left = NULL;
                }

                if(curr->right){
                    q.push(curr->right);

                    if(dlt[curr->right->val])
                        curr->right = NULL;
                }

                if(dlt[curr->val]){
                    if(curr->left)
                        ans.push_back(curr->left);

                    if(curr->right)
                        ans.push_back(curr->right);
                }

                else if(ans.empty())
                    ans.push_back(curr);
            }
        }
        
        return ans;
    }
};
