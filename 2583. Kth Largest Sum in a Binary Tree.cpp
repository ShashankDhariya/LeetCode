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

#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<ll, vector<ll>, greater<ll>> pq; 
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            ll sum = 0;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                sum += curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(pq.size() == k){
                if(pq.top() < sum)
                    pq.pop();
                else
                    continue;
            }
            pq.push(sum);
        }

        return pq.size() == k? pq.top(): -1;
    }
};
