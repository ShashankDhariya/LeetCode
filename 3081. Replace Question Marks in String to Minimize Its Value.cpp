class Solution {
public:
    string minimizeStringValue(string s) {
        string t = s;
        vector<int> freq(26, 0);
        
        for(auto& ch: t){
            if(ch != '?')
                freq[ch - 'a']++;
        }
        
        for(auto& ch: t){
            if(ch == '?'){
                int mini = 1e9;
                for(int i=25;i>-1;i--){
                    if(mini >= freq[i]){
                        mini = freq[i];
                        ch = 'a' + i;
                    }
                }
                freq[ch - 'a']++;
            }
        }
        
        vector<int> res;
        int n = t.length();
        for(int i=0;i<n;i++){
            if(s[i] == '?')
                res.push_back(t[i]);
        }
        
        int idx = 0;
        sort(res.begin(), res.end());
        for(int i=0;i<n;i++){
            if(s[i] == '?')
                t[i] = res[idx++];
        }
        
        return t;
    }
};
