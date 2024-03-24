class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<long long, long long> mp;
        map<long long, long long> fp;
        
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i=0;i<n;i++){
            if(mp[nums[i]] != 0){
                long long prev = mp[nums[i]];
                mp[nums[i]] += freq[i];
                long long curr = mp[nums[i]];
                
                fp[prev]--;
                if(fp[prev] == 0)
                    fp.erase(prev);
                fp[curr]++;
            }
            
            else {
                mp[nums[i]] = freq[i];
                fp[freq[i]]++;
            }
            
            auto res = fp.end();
            if(!fp.empty()) {
                --res;
                ans[i] = res->first;
            }
        }
        
        return ans;
    }
};
