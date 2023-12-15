class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> path;

        for(auto p: paths)
            path[p[0]] = p[1];

        string city = paths[0][0];
        while(path.find(city) != path.end())
            city = path[city];

        return city;
    }
};
