class DSU{
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;            
        }
    }
    
    int findPar(int node){
        if(node == parent[node])
            return node;
            
        return parent[node] = findPar(parent[node]);
    }
    
    void unionRank(int u, int v){
        int par1 = findPar(u);
        int par2 = findPar(v);
        
        if(par1 == par2)
            return;
            
        if(rank[par1] < rank[par2]){
            parent[par1] = par2;
        }
        
        else if(rank[par2] < rank[par1]){
            parent[par2] = par1;
        }
         
        else {
            parent[par2] = par1;
            rank[par1]++;
        }   
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            dsu.unionRank(u, v);
        }
        
        vector<int> andOp(n, -1);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int parU = dsu.findPar(u);
            int parV = dsu.findPar(v);
            if(parU == parV){
                if(andOp[parU] == -1)
                    andOp[parU] = w;
                else 
                    andOp[parU] &= w;
            }
        }
        
        int size = query.size();
        vector<int> ans;
        for(auto q: query){
            int u = q[0];
            int v = q[1];
            
            if(u == v){
                ans.push_back(0);
                continue;
            }
            
            int parU = dsu.findPar(u);
            int parV = dsu.findPar(v);
            
            if(parU != parV)
                ans.push_back(-1);
            
            else 
                ans.push_back(andOp[parU]);
        }
        
        return ans;
    }
};
