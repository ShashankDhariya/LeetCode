class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        int n = s.length();
        string ans = "";
        vector<vector<char>> res(numRows, vector<char> (n, '0'));
        int dir = 0;

        int i = 0;
        int j = 0;
        for(int a=0;a<n;a++){
            res[i][j] = s[a];
            if(dir == 0){
                if(i+1 < numRows )
                    i++;
                
                else {
                    dir = 1;
                    i--;
                    j++;
                }
            }  
            else{
                if(i-1 > -1){
                    i--;
                    j++;
                }
                else {
                    dir = 0;
                    i++;
                }
            }  
        }
        
        for(auto num: res){
            for(auto c: num){
                if(c != '0')
                    ans.push_back(c);
            }
        }
        return ans;
    }
};
