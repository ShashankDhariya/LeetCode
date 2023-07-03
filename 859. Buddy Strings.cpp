class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return 0;

        unordered_map<int, int> mp;
        for(auto ch: s) mp[ch]++;

        if(s == goal){
            for(auto m: mp){
                if(m.second >= 2)
                    return 1;
            }
            return 0;
        }

        for(auto g:goal){
            if(mp[g] == 0)
                return 0;
            mp[g]--;
            if(mp[g] == 0)
                mp.erase(g);
        }
        if(!mp.empty()) return 0;

        int i = -1;
        int j = -1;
        int n = goal.size();
        for(int k=0;k<n;k++){
            if(goal[k] == s[k])
                continue;
            else if(i == -1 && goal[k] != s[k])
                i = k;
            else if(j == -1 && goal[k] != s[k])
                j = k;
            else 
                return 0;
        }
        swap(s[i], s[j]);
        return s == goal? 1:0;
    }
};
