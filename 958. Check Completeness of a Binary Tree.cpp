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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root){
            res.push_back({1});
            q.push(root);
        }

        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                if(curr->left){
                    v.push_back(1);
                    q.push(curr->left);
                }
                else 
                    v.push_back(-1);

                if(curr->right){
                    v.push_back(1);
                    q.push(curr->right);
                }
                else 
                    v.push_back(-1);
            }
            res.push_back(v);
        }

        int n = res.size();
        for(int i=0;i<n-1;i++){
            bool b = false;
            int size = res[i].size();
            for(int j=0;j<size;j++){
                if(i != n-2 && res[i][j] == -1)
                    return false;
                if(i == n-2){
                    if(!b && res[i][j] == -1)
                        b = true;
                    else if(b && res[i][j] == 1)
                        return false;
                }
            }
        }
        return true;
    }
};
