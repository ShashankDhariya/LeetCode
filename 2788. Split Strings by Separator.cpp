class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        
        for(auto word: words){
            string res = "";
            for(auto w: word){
                if(w != separator)
                    res += w;
                else if(res != ""){
                    ans.push_back(res);
                    res = "";
                }
            }
            if(res != "")
                ans.push_back(res);
        }
        return ans;
    }
};
