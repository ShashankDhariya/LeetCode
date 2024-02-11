class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string & a, string& b){
            return a.length() < b.length();
        });
        
        unordered_map<int, int> freq;
        for(auto word: words){
            for(auto ch: word)
                freq[ch]++;
        }
        
        
        int ans = 0;
        for(auto word: words){
            int len = word.length();
            
            bool odd = 0;
            if(len % 2 == 1){
                odd = 1;
                len--;
            }
                
            
            for(auto& f: freq){
                if(f.second % 2 == 1 && odd){
                    f.second--;
                    break;
                }
            }
            
            for(auto& f: freq){                
                if(f.second % 2 == 0){
                    if(len > f.second){
                        len -= f.second;
                        f.second = 0;
                    }
                    else {
                        f.second -= len;
                        len = 0;
                    }
                }
                
                else {
                    if(len > (f.second - 1)){
                        len -= (f.second - 1);
                        f.second = 1;
                    }
                    else {
                        f.second -= len;
                        len = 0;
                    }
                }
            }
            
            if(len == 0)
                ans++;
            else 
                break;
        }
        
        
        return ans;
    }
};
