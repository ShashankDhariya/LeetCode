class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = s;
        
        int n = s.length();
        for(int i=0;i<n;i++){
            int op1 = 1e9;
            int op2 = 1e9;
            
            if(((s[i] - 'a') + k) > 25){
                ans[i] = 'a';
                op1 = (26 - (s[i] - 'a'));
            }
            
            if(((s[i] - 'a') - k) < 1){
                ans[i] = 'a';
                op2 = (s[i] - 'a');
            }
            
            
            if(op1 < op2)
                k -= op1;
            else 
                k -= op2;
            
            if(op1 == 1e9 && op2 == 1e9) {
                ans[i] = (s[i] - k);
                break;
            }
        }
        
        return ans;
    }
};
