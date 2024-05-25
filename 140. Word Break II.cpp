class Solution {
public:
    struct trie{
        trie* links[26];
        bool ends = 0;

        bool contains(int ch){
            return links[ch] != NULL;
        }

        void putChar(int ch, trie* newNode){
            links[ch] = newNode;
        }

        trie* next(int ch){
            return links[ch];
        }
    };

    void solution(int idx, int& n, string& s, trie* root, string str, vector<string>& ans){
        if(idx == n){
            str.pop_back();
            ans.push_back(str);
            return;
        }

        trie* node = root;
        int i = idx;
        while(i < n && node && node->contains(s[i] - 'a')){
            str += s[i];
            node = node->next(s[i] - 'a');
            i++;
            if(node->ends){
                str.push_back(' ');
                solution(i, n, s, root, str, ans);
                str.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trie* root = new trie();
        for(auto word: wordDict){
            trie* node = root;
            for(auto ch: word){
                if(!node->contains(ch - 'a'))
                    node->putChar(ch - 'a', new trie());
                node = node->next(ch - 'a');
            }
            node->ends = 1;
        }

        int n = s.length();
        vector<string> ans;
        solution(0, n, s, root, "", ans);
        return ans;
    }
};
