class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        
        unordered_map<string, bool> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(access_times[i][0] == access_times[j][0] && access_times[j][0] == access_times[k][0]){
                        vector<int> times;
                        times.push_back(stoi(access_times[i][1]));
                        times.push_back(stoi(access_times[j][1]));
                        times.push_back(stoi(access_times[k][1]));
                        
                        sort(times.begin(), times.end());
                        int t = 100 + times[0];
                        
                        if((times[1] >= times[0] && times[1] < t) && (times[2] >= times[0] && times[2] < t))
                            mp[access_times[i][0]] = 1;
                    }
                }
            }
        }
        
        vector<string> ans;
        for(auto m: mp){
            if(m.second)
                ans.push_back(m.first);
        }
        
        return ans;
    }
};
