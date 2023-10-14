class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        
        int prev = -1;
        for(int i=0;i<n;i++){
            if(prev != groups[i]){
                prev = groups[i];
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};
