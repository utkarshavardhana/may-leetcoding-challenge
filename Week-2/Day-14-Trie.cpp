class Trie {
public:
    class TrieNode{
    public:
        bool eow = false;
        unordered_map<char, TrieNode*> m;
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->m.find(c) == node->m.end()) {
                node->m[c] = new TrieNode;
            }
            node = node->m[c];
        }
        node->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->m.find(c) == node->m.end()) {
                return false;
            }
            node = node->m[c];
        }
        return node->eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            if(node->m.find(c) == node->m.end()) {
                return false;
            }
            node = node->m[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
