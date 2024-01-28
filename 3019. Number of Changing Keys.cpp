class Solution {
public:
    char to_lower(char ch){
        return ch < 91? ch: ch - 32;
    }
    
    int countKeyChanges(string s) {
        int ans = 0;
        
        int n = s.length();
        for(int i=0;i<n-1;i++){
            if(to_lower(s[i]) != to_lower(s[i+1]))
                ans++;
        }
        
        return ans;
    }
};
