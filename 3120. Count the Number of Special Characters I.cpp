class Solution {
public:
    int numberOfSpecialChars(string word) {
        int d = 0;
        int D = 0;
        for(auto w: word){
            if(w > 91)
                d |= 1 << (w - 'a');
            
            else 
                D |= 1 << (w - 'A');
        }
        
        int ans = 0;
        for(int i=0;i<26;i++){
            int checker = 1 << i;
            if((checker & d) && (checker & D))
                ans++;
        }
        
        return ans;
    }
};
