class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> res(26);
        
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] != '*'){
                res[s[i] - 'a'].push_back(i);
                continue;
            }
            
            for(int j=0;j<26;j++){
                if(!res[j].empty()){
                    s[res[j].back()] = '.';
                    res[j].pop_back();
                    break;
                }
            }
        }
        
        string ans = "";
        for(auto ch: s){
            if(ch != '.' && ch != '*')
                ans += ch;
        }
        
        return ans;
    }
};
