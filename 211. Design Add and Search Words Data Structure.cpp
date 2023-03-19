struct Node{
    Node* links[26];
    bool flag = false;
};

class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* ptr = root;
        for(auto w: word){
            if(ptr->links[w - 'a'] == NULL)
                ptr->links[w - 'a'] = new Node();
            ptr = ptr->links[w - 'a'];
        }
        ptr->flag = true;
    }

    bool search(string word) {
        return searchHelp(root, word, 0);
    }

    bool searchHelp(Node* node, string word, int i){
        if(!node)
            return false;
        if(i == word.length())
            return node->flag;

        if(word[i] == '.'){
            for(auto& child: node->links){
                if(searchHelp(child, word, i+1))
                    return true;
            }
            return false;
        }
        else {
            if(node->links[word[i] - 'a'] == NULL)
                return false;
        }
        node = node->links[word[i] - 'a'];
        return searchHelp(node, word, i+1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
