class Solution {
public:
    
    bool vowel(string& word){
        for(auto w: word){
            if(w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U')
                return 1;
            
            if(w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u')
                return 1;
        }
        
        return 0;
    }
    
    bool consonant(string& word){
        for(auto w: word){
            if(w >= 'A' && w <= 'Z' && (w != 'A' && w != 'E' && w != 'I' && w != 'O' && w != 'U'))
                return 1;
            
            if(w >= 'a' && w <= 'z' && (w != 'a' && w != 'e' && w != 'i' && w != 'o' && w != 'u'))
                return 1;
        }
        
        return 0;
    }
    
    bool check(string& word){
        for(auto w: word){
            if(w == '@' || w == '$' || w == '#')
                return 0;
        }
            
        for(auto w: word){
            if((w >= '0' && w <= '9') || (w >= 'A' && w <= 'Z') || (w >= 'a' && w <= 'z')) 
                return 1;
        }
        
        return 0;
    }
    
    bool isValid(string word) {
        int n = word.length();
        if(n < 3)
            return 0;
        
        if(!vowel(word))
            return 0;
        
        if(!consonant(word))
            return 0;
        
        if(!check(word))
            return 0;
        
        return 1;
    }
};
