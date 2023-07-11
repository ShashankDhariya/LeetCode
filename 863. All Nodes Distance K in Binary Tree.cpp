/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode* , TreeNode*> mp;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                if(curr->left){
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }

        q.push(target);
        unordered_map<TreeNode*, int> vis;
        vis[target]++;

        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                if(k == 0)
                    ans.push_back(curr->val);
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]++;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]++;
                }
                if(mp.find(curr) != mp.end() && !vis[mp[curr]]){
                    q.push(mp[curr]);
                    vis[mp[curr]]++;
                }
            }
            if(k == 0)
                return ans;
            k--;
        }
        return ans;
    }
};
