class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> mp;

        pair<int, int> curr = {0, 0};
        mp[curr] = 1;
        for(auto p: path){
            pair<int, int> dir;
            if(p == 'E')   
                dir = {curr.first+1, curr.second};
            
            else if(p == 'W')   
                dir = {curr.first-1, curr.second};

            else if(p == 'N')   
                dir = {curr.first, curr.second+1};

            else
                dir = {curr.first, curr.second-1};

            if(mp[dir])
                return 1;
            curr = dir;
            mp[curr] = 1;
        }

        return 0;
    }
};
