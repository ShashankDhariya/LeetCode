class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        unordered_map<char, int> mp; 

        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]){
                mp.clear();
                ans++;
            }
            mp[s[i]]++;
        }
        return ans+1;
    }
};
