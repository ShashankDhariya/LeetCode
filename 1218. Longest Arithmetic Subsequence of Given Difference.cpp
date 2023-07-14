class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 0;

        unordered_map<int, int> mp;
        for(auto a: arr){
            if(mp.find(a - difference) != mp.end())
                mp[a] = 1 + mp[a - difference];
            else 
                mp[a] = 1;
            ans = max(ans, mp[a]);
        }
        return ans;
    }
};
