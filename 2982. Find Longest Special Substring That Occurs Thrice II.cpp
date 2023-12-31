class Solution {
public:
    int maximumLength(string s) {
        char prev = s[0];
        
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        int i = 0;
        while(i < n){
            int j = i+1;
            while(j < n && s[i] == s[j])
                j++;
            
            mp[s[i]].push_back(j - i);
            i = j;
        }
        
        int ans = 0;
        for(auto m: mp){
            auto res = m.second;
            int size = res.size();
                
            sort(res.begin(), res.end());      
            ans = max(ans, res[size - 1] - 2);
            
            if(size >= 2){
                if(res[size-2] == res[size-1])
                    ans = max(ans, res[size-1]-1);
                
                else if(res[size-1] > 1)
                    ans = max(ans, min(res[size-2], res[size-1]));
            }
            
            if(size > 2)
                ans = max(ans, min({res[size-1], res[size-2], res[size-3]}));
        }
        
        return ans > 0? ans: -1;
    }
};
