/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void dfs(Node* curr, vector<Node* >& vis, Node *ans){
        vis[curr->val] = ans;
        for(auto num: curr->neighbors){
            if(!vis[num->val]){
                Node* newClone = new Node(num->val);
                (ans->neighbors).push_back(newClone);
                dfs(num, vis, newClone);
            }
            else 
                ans->neighbors.push_back(vis[num->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return node;

        vector<Node* > vis(101, NULL);
        Node* ans = new Node(node->val);
        dfs(node, vis, ans);
        return ans;
    }
};
