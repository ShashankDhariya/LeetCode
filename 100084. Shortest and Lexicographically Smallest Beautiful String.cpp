class Solution {
public:
    
    bool check(int i, int j, string& s, int k){
        int ctr = 0;
        for(int idx=i;idx<=j;idx++)
            ctr += (s[idx] == '1');
        
        return (ctr == k);       
    }
    
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int len = 1e9;
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i, j, s, k)){
                    string str = s.substr(i, j-i+1);
                    if(str == "" || str.length () < len){
                        len = str.length();
                        ans = str;
                    }
                    else if(str.length() == len && str < ans)
                        ans = str;
                }
            }
        }
        
        return ans;
    }
};
