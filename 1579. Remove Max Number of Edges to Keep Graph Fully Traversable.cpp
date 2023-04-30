class DSU {
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int Find(int x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }
    
    bool Union(int x, int y){
        int xset = Find(x), yset = Find(y);
        if(xset != yset){
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n+1);
        DSU dsuBob(n+1);

        int ans = 0;
        int alice = 0;
        int bob = 0;

        for(auto edge: edges){
            if(edge[0] == 3){
                if(dsuAlice.Union(edge[1], edge[2])){
                    dsuBob.Union(edge[1], edge[2]);
                    alice++;
                    bob++;
                }
                else 
                    ans++;
            }
        }

        for(auto edge: edges){
            if(edge[0] == 1){
                if(dsuAlice.Union(edge[1], edge[2]))
                    alice++;
                else 
                    ans++;
            }
            else if(edge[0] == 2){
                if(dsuBob.Union(edge[1], edge[2]))
                    bob++;
                else 
                    ans++;
            }
        }
        return (alice == n-1 && bob == n-1)? ans: -1;
    }
};
