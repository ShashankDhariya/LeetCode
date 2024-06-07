class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string& b){
            return a.length() < b.length();
        });

        string ans = "";
        string word = "";
        int n = sentence.length();
        for(int i=0;i<n;i++){
            if(i != n-1 && sentence[i] != ' '){
                word += sentence[i];
                continue;
            }

            if(i == n-1)
                word += sentence[i];

            bool yes = 1;
            for(auto dict: dictionary){
                if(dict.length() > word.length())
                    break;

                int size = dict.length();
                if(dict == word.substr(0, size)){
                    ans += dict;
                    yes = 0;
                    break;
                }
            }
            if(yes)
                ans += word;
            ans += ' ';
            word = "";
        }

        ans.pop_back();
        return ans;
    }
};
