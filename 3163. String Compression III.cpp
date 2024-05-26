class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int size = 1;
        
        int n = word.length();
        for(int i=1;i<n;i++) {
            if(size < 9 && word[i] == word[i-1])
                size++;
            
            else {
                ans += to_string(size);
                ans += word[i-1];
                size = 1;
            }
        }
        
        if(size) {
            ans += to_string(size);
            ans += word[n-1];
        }
        
        return ans;
    }
};
