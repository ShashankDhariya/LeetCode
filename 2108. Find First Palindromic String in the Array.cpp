class Solution {
public:

    bool isPallindrome(string& word){
        int i = 0;
        int j = word.length() - 1;

        while(i < j){
            if(word[i++] != word[j--])
                return 0;
        }

        return 1;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto word: words){
            if(isPallindrome(word))
                return word;
        }

        return "";
    }
};
