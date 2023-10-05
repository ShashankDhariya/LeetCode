class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float, int> mp;
        for(auto a: arr){
            if(mp[a/2.0] || mp[2.0*a])
                return 1;
            mp[a]++;
        }
        return 0;
    }
};
