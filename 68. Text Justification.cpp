class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int n = words.size();

        while(i < n){
            int lineLength = words[i].length();
            int j = i + 1;

            while(j < n && lineLength + words[j].length() + (j-i) <= maxWidth){
                lineLength += words[j].length();
                j++;
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;

            string line = "";
            if(numWords == 1 || j == n){
                line = words[i];
                for(int k=i+1;k<j;k++)
                    line += (' ' + words[k]);
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spaceBetweenWords = numSpaces / (numWords-1);
                int extraSpaces = numSpaces % (numWords - 1);

                line = words[i];
                for(int k=i+1;k<j;k++){
                    line += string(spaceBetweenWords, ' ');
                    if(extraSpaces > 0){
                        line += ' ';
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
