class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.length();

        vector<string> ans;
        int words = 0;
        int maxLen = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                words++;
                len = 0;
            }
            else 
                maxLen = max(maxLen, ++len);
        }

        vector<vector<char>> res(maxLen, vector<char> (words+1, ' '));

        int idx = 0;
        int j = 0;
        while(idx < n){
            int i = 0;
            while(idx < n && s[idx] != ' '){
                res[i][j] = s[idx];
                idx++;
                i++;
            }
            j++;
            idx++;
        }

        for(auto r: res){
            string str = "";
            int ind = 0;
            for(int i=0;i<r.size();i++){
                if(r[i] != ' ')
                    ind = i;
                str += r[i];
            }
            if(str.size() != ind+1)
                str.resize(ind+1);
            ans.push_back(str);
        }

        return ans;
    }
};
