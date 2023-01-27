class Solution {
public:

    bool canConcatenate(string word, set<string>& s){

        for(int i=1;i<word.length();i++){
            string suffix = word.substr(i,word.length()-i);
            if(s.find(word.substr(0,i)) != s.end() && (s.find(suffix) != s.end() || canConcatenate(suffix, s)))
                return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        set<string> s;

        for(auto word: words)
            s.insert(word);

        for(auto word: s){
            if(canConcatenate(word, s))
                ans.push_back(word);
        }
        return ans;
    }
};
