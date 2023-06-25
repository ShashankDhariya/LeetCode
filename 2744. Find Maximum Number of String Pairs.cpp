class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        unordered_set<string> s;
        
        for(auto w: words){
            string word = w;
            reverse(w.begin(), w.end());
            if(s.find(w) != s.end()){
                ans++;
                s.erase(w);
            }
            else 
                s.insert(word);
        }
        return ans;
    }
};
