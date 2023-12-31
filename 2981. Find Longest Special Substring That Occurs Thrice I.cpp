class Solution {
public:
    int maximumLength(string s) {        
        unordered_map<string, int> freq;
        
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int size = j-i+1;
                string str = s.substr(i, size);
                if(str[0] == str[size-1])
                    freq[str]++;
                
                else 
                    break;
            }
        }
        
        int ans = -1;
        for(auto f: freq){
            if(f.second > 2)
                ans = max(ans, (int)f.first.length());
        }
        
        return ans;
    }
};
