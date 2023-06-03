class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int right = 0;

        for(auto ch: s){
            if(ch == '(')
                right++;

            else if(right > 0)
                right--;

            else
                left++;
        }
        return left + right;
    }
};
