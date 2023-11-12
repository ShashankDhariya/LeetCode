class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> buses;

        int n = routes.size();
        for(int i=0;i<n;i++){
            int bId = i;
            auto stops = routes[i];
            for(auto stop: stops)
                buses[stop].push_back(bId);
        }

        queue<pair<int, int>> q;
        unordered_map<int, bool> bVis, stopVis;
        q.push({source, 0});

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                int currStop = curr.first;
                int currBuses = curr.second;

                if(currStop == target)
                    return currBuses;

                for(auto bus: buses[currStop]){
                    if(bVis[bus])
                        continue;
                    bVis[bus] = 1;

                    for(auto stop: routes[bus]){
                        if(stopVis[stop])
                            continue;
                        stopVis[stop] = 1;
                        q.push({stop, currBuses + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};
