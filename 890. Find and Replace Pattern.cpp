class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        unordered_map<char, vector<int>> mp1;
        
        int size = pattern.size();
        for(int i=0;i<size;i++)
            mp1[pattern[i]].push_back(i);

        int n = words.size();
        for(int i=0;i<n;i++){
            unordered_map<char, vector<int>> mp2;
            for(int j=0;j<words[i].size();j++)
                mp2[words[i][j]].push_back(j);

            ans.push_back(words[i]);

            for(int j=0;j<size;j++){
                auto vec1 = mp1[pattern[j]];
                auto vec2 = mp2[words[i][j]];
                if(vec1.size() != vec2.size()){
                    ans.pop_back();
                    break;
                }

                bool b = false;
                for(int k=0;k<vec1.size();k++){
                    if(vec1[k] != vec2[k]){
                        ans.pop_back();
                        b = true;
                        break;
                    }
                }
                if(b)
                    break;
            }
        }
        return ans;
    }
};
