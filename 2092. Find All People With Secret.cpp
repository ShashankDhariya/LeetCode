class DSU{
public: 
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int Find(int node){
        return parent[node] = (parent[node] == node)? node: Find(parent[node]);
    }

    void Reset(int node){
        parent[node] = node;
    }

    void Union(int node1, int node2){
        int par1 = Find(node1);
        int par2 = Find(node2);
        if(par1 != par2){
            rank[par1] < rank[par2]? parent[par1] = par2: parent[par2] = par1;
            rank[par1] += rank[par1] == rank[par2]? 1: 0;
        }
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [&](vector<int>& a, vector<int>& b){
            if(a[2] == b[2])
                return a[0] < b[0];
            return a[2] < b[2];
        });

        DSU dsu(n);

        dsu.Union(0, firstPerson);
        for(int i=0;i<meetings.size();i){
            int time = meetings[i][2];
            vector<int> currPeople;

            while(i < meetings.size() && meetings[i][2] == time){
                dsu.Union(meetings[i][0], meetings[i][1]);
                currPeople.push_back(meetings[i][0]);
                currPeople.push_back(meetings[i][1]);
                i++;
            }

            for(auto p: currPeople){
                if(dsu.Find(p) != dsu.Find(0))
                    dsu.Reset(p);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dsu.Find(i) == dsu.Find(0))
                ans.push_back(i);
        }

        return ans;
    }
};
