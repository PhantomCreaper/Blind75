class TrieNode {
public:
    bool isEndOfWord;
    std::vector<TrieNode*> child;

    TrieNode() : isEndOfWord(false), child(26, nullptr) {}
};


class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *currentNode = root;
        for(char c:word){
            int i = c - 'a';
            if(!currentNode->child[i]){
                currentNode->child[i] = new TrieNode();
            }
            currentNode = currentNode->child[i];
        }
        currentNode->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *currentNode = root;
        for(char c:word){
            int i = c - 'a';
            if(!currentNode->child[i]){
                return false;
            }
            currentNode = currentNode->child[i];
        }
        return currentNode!=nullptr && currentNode->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *currentNode = root;
        for(char c:prefix){
            int i = c - 'a';
            if(!currentNode->child[i]){
                return false;
            }

            currentNode = currentNode->child[i];
        }
        return currentNode!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
