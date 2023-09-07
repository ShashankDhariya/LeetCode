/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

T.C. - O(n)
S.C. - O(1)  
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;

        Node* prev = root;
        Node* curr = NULL;

        while(prev){
            curr = prev;
            while(curr && curr->left){
                curr->left->next = curr->right;
                if(curr->next)
                    curr->right->next = curr->next->left;
                    
                curr = curr->next;
            }

            prev = prev->left;
        }

        return root;
    }
};

T.C. - O(n)
S.C. - O(n) (queue)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;

        Node* ans = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();

                if(i < n-1) curr->next = q.front();

                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};
