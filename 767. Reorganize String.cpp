// O(n)
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n = s.length();
        for(auto str: s){
            freq[str - 'a']++;
            if(freq[str - 'a'] > ((n+1)/2))
                return "";
        }

        int maxFreq = 0;
        char maxChar;
        for(int i=0;i<26;i++){
            if(freq[i] > maxFreq){
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }                
        }

        int i = 0;
        string ans = s;
        for(int a=0;a<maxFreq;a++){
            ans[i] = maxChar;
            i += 2;
        }
        freq[maxChar - 'a'] = 0;

        for(int a=0;a<26;a++){
            while(freq[a]-- > 0){
                if(i >= n)
                    i = 1;
                ans[i] = char('a' + a);
                i += 2;
            }
        }
        return ans;
    }
};

// Priority Queue and Hash Map
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int n = s.length();
        for(auto str: s){
            freq[str]++;
            if(freq[str] > ((n+1)/2))
                return "";
        }

        priority_queue<pair<int, char>> pq;
        for(auto f: freq)
            pq.push({f.second, f.first});
        freq.clear();

        int i = 0;
        while(pq.size()){
            int f = pq.top().first;
            char ch = pq.top().second;
            for(int a=0;a<f;a++){
                s[i] = ch;
                if(i == n-2)
                    i++;
                i = (i+2) % n;
            }
            pq.pop();
        }
        return s;
    }
};
