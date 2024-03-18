class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(auto ch: word)
            freq[ch - 'a']++;
        
        sort(freq.rbegin(), freq.rend());
        while(!freq.empty() && freq.back() == 0)
            freq.pop_back();
        
        
        long long ans = 1e9;
        long long prev = 0;
        while(!freq.empty()){
            int mini = freq.back();
            freq.pop_back();
            long long res = prev;
            
            for(auto f: freq){
                if(f > k + mini)
                    res = res + f - k - mini;
            }
            
            ans = min(ans, res);
            prev += mini;
        }
                
        return ans;
    }
};
