class Solution {
public:

    struct trie{
        trie* links[26];
        bool isEnd = 0;

        bool contains(int idx){
            return links[idx] != NULL;
        }

        void putChar(int idx, trie* node){
            links[idx] = node;
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        trie* node = new trie();
        for(auto dict: dictionary){
            trie* curr = node;
            for(auto ch: dict){
                if(!curr->contains(ch - 'a')) {
                    curr->putChar(ch - 'a', new trie());
                    curr = curr->links[ch - 'a'];
                }

                else 
                    curr = curr->links[ch - 'a'];
            }
            curr->isEnd = 1;
        }

        string ans = "";

        int n = sentence.size();
        for(int i=0;i<n;i++){
            bool found = 0;
            bool notFound = 0;
            trie* curr = node;
            string word = "";
            while(i < n && sentence[i] != ' ') {
                if(found)
                    i++;

                else if(notFound){
                    word += sentence[i];
                    i++;
                }

                else if(curr->isEnd){
                    found = 1;
                    i++;
                }

                else if(!curr->contains(sentence[i] - 'a')){
                    notFound = 1;
                    word += sentence[i];
                    i++;
                }

                else {
                    curr = curr->links[sentence[i] - 'a'];
                    word += sentence[i];
                    i++;
                }
            }
            
            ans += (word + " ");
        }

        ans.pop_back();
        return ans;
    }
};
