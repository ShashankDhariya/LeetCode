class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0;
        int idx2 = 0;

        int i = 0;
        int j = 0;
        while(idx1 < word1.size() && idx2 < word2.size()){
            if(word1[idx1][i] != word2[idx2][j])
                return 0;
            
            if(i == word1[idx1].size() - 1){
                idx1++;
                i = 0;
            }
            else
                i++;

            if(j == word2[idx2].size() - 1){
                idx2++;
                j = 0;
            }

            else
                j++;
        }

        return idx1 == word1.size() && idx2 == word2.size();
    }
};
