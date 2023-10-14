class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans;
        vector<int> res;
        
        int idx = -1;
        for(auto word: words){
            if(word == "prev"){
                if(idx < 0)
                    ans.push_back(-1);
                else 
                    ans.push_back(res[idx--]);
            }
            else {
                res.push_back(stoi(word));
                idx = res.size() - 1;
            }
        }
        
        return ans;
    }
};
