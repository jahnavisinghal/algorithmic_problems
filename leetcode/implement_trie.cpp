ass TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char alphabet=' ') {
        val = alphabet;
    }
    char val; // value of the node
    vector<TrieNode*> listOfChildPtrs;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        int j = 0;
        while(j < word.size()) {
            bool found = false;
            for(int i = 0; i < ptr->listOfChildPtrs.size(); i++) {
                TrieNode* child = ptr->listOfChildPtrs[i];
                if(word[j] == child->val) {
                    j++;
                    found = true;
                    ptr = child;
                    break;
                }
            }
            if(!found) {
                // insert this char into this level
                TrieNode* node = new TrieNode(word[j++]);
                ptr->listOfChildPtrs.push_back(node);
                ptr = node;
            }
        }
        TrieNode* n = new TrieNode('-');
        ptr->listOfChildPtrs.push_back(n);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        int j = 0;
        while(j < word.size()) {
            bool found = false;
            for(int i = 0; i < ptr->listOfChildPtrs.size(); i++) {
                TrieNode* child = ptr->listOfChildPtrs[i];
                if(child->val == word[j]) {
                    found = true;
                    ptr = child;
                    j++;
                    break;
                }
            }
            if(!found) {
                return false;
            }
        }
        for(int i = 0; i < ptr->listOfChildPtrs.size(); i++) {
            if(ptr->listOfChildPtrs[i]->val == '-') {
                return true;
            }
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        int j = 0;
        while(j < prefix.size()) {
            bool found = false;
            for(int i = 0; i < ptr->listOfChildPtrs.size(); i++) {
                TrieNode* child = ptr->listOfChildPtrs[i];
                if(child->val == prefix[j]) {
                    found = true;
                    ptr = child;
                    j++;
                    break;
                }
            }
            if(!found) {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
