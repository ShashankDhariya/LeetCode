class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> freq(128, pair<int, char> ({0, ' '}));
        for(auto ch: s){
            freq[ch].first++;
            freq[ch].second = ch;
        }

        sort(freq.rbegin(), freq.rend());

        string ans = "";
        for(int i=0;i<128;i++){
            string str(freq[i].first, freq[i].second);
            ans += str;
        }

        return ans;
    }
};
