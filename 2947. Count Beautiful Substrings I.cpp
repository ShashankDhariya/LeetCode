class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int beautifulSubstrings(string s, int k) {
        int con = 0;
        int vow = 0;
        
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            con = vow = 0;
            for(int j=i;j<n;j++){
                isVowel(s[j])? vow++: con++;
                
                if(vow == con && (vow * con) % k == 0)
                    ans++;
            }
        }
        
        return ans;
    }
};
