class Solution {
public:
    vector<string> cellsInRange(string s) {
        int n = s.length();
        vector<string> ans;

        int rows = s[1] - '0';
        int rowe = s[4] - '0';

        char cols = s[0];
        char cole = s[3];

        while(cols <= cole){
            string str;
            str.push_back(cols);
            for(int i=rows;i<=rowe;i++){
                str.push_back(i + '0');
                ans.push_back(str);
                str.pop_back();
            }
            cols++;
        }
        return ans;
    }
};
