class Solution {
public:
    
    bool check(string& str, int& n){
        for(int i=1;i<n;i++){
            if(str[i-1] == '0' && str[i] == '0')
                return 0;
        }
        
        return 1;
    }
    
    void solution(int idx, int& n, string str, vector<string>& ans){
        if(idx == n){
            if(check(str, n))
                ans.push_back(str);
            return;
        }
        
        solution(idx+1, n, str + '1', ans);
        solution(idx+1, n, str + '0', ans);
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        
        solution(0, n, "", ans);
        
        return ans;
    }
};
