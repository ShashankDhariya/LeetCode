class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> res;
        istringstream ss(s);
        string w;

        while(ss>>w){
            int size = w.size();
            int ind = w[size-1] - '0';
            w.pop_back();
            res.push_back({ind, w});
        }

        sort(res.begin(), res.end());
        string ans = "";
        for(auto r: res)
            ans += r.second + ' ';
        ans.pop_back();
        return ans;
    }
};
