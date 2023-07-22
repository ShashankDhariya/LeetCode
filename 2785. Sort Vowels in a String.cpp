class Solution {
public:
    string sortVowels(string s) {
        string vowel = "";
        
        for(auto ch: s){
            if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u')
                vowel += ch;
            if(ch == 'A' || ch == 'I' || ch == 'E' || ch == 'O' || ch == 'U')
                vowel += ch;
        }
        sort(vowel.begin(), vowel.end());
        
        int i = 0;
        for(auto& ch: s){
            if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u')
                ch = vowel[i++];
            else if(ch == 'A' || ch == 'I' || ch == 'E' || ch == 'O' || ch == 'U')
                ch = vowel[i++];
        }       
        return s;
    }
};
