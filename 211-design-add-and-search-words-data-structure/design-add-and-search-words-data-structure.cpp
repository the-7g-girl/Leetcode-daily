class WordDictionary {
public:
    struct TrieNode {
        TrieNode* childs[26];
        bool isLast;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                childs[i] = NULL;
            }
            isLast = false;
        }
    };

    void addword(TrieNode* root, string s) {
        if (s.length() == 0) {
            root->isLast = true;
            return;
        }
        int index = s[0] - 'a';
        TrieNode* child;
        if (root->childs[index] != NULL) {
            child = root->childs[index];
        } else {
            child = new TrieNode();
            root->childs[index] = child;
        }
        addword(child, s.substr(1));
        return;
    }

    bool searchword(TrieNode* root, string s) {
        if (s.length() == 0) {
            return root->isLast;
        }

        int index = s[0] - 'a';
        TrieNode* child;
        if (s[0] == '.') {
            bool flag = false;
            for (int i = 0; i < 26; i++) {
                if (root->childs[i] != NULL &&
                    searchword(root->childs[i], s.substr(1))) {
                        flag=true;
                    return true;
                }
            }
            if (!flag)
                return false;
        } else if (root->childs[index] != NULL) {
            child = root->childs[index];
        } else {
            return false;
        }
        return searchword(child, s.substr(1));
    }

    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) { return addword(root, word); }

    bool search(string word) { return searchword(root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
