class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1)
                indegree[leftChild[i]]++;

            if(rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        int root = -1;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                if(root == -1)
                    root = i;
                else 
                    return 0;
            }
        }
        if(root == -1)
            return 0;

        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(root);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(vis[curr] == 1)
                return 0;

            vis[curr] = 1;
            if(leftChild[curr] != -1)
                q.push(leftChild[curr]);

            if(rightChild[curr] != -1)
                q.push(rightChild[curr]);
        }

        int ctr = 0;
        for(auto v: vis)
            ctr += v;

        return ctr == n;
    }
};
