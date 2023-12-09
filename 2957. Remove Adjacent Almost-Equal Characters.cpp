class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0;
        
        int n = word.size();
        for(int i=1;i<n;i++){
            if(word[i-1] == word[i] || abs(word[i] - word[i-1]) == 1){
                word[i] = '1';
                ans++;
            }
        }
        
        return ans;
    }
};
