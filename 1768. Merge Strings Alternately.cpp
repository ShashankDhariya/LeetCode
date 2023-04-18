class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string str = "";

        int i = 0;
        int j = 0;
        while(i < len1 || j < len2){
            if(i >= len1){
                str += word2.substr(j, len2 - j);
                j = len2;
            }

            else if(j >= len2){
                str += word1.substr(i, len1 - i);
                i = len1;
            }

            else {
                str += word1[i++];
                str += word2[j++];
            }
        }
        return str;
    }
};
