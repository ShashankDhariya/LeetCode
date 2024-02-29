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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int even = 0;
            int odd = 1e7;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                if((level % 2) == 0){
                    if(even >= curr->val || (curr->val % 2) == 0)
                        return 0;
                    even = curr->val;
                }

                else {
                    if(odd <= curr->val || (curr->val % 2) == 1)
                        return 0;
                    odd = curr->val;
                }

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            level++;
        }

        return 1;
    }
};
