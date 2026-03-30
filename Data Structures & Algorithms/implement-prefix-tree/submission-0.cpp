
class TrieNode{
public:
    TrieNode* children[26];
    string word =""; // For easier lookup
    
    TrieNode(){
        for(int i=0; i<26; i++) children[i] = nullptr;
    }

    ~TrieNode(){
        for(int i=0; i<26; i++){
            if(children[i] != nullptr){
                delete children[i];
            }
        }
    }

};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->word = word;
        
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur -> children[i] == nullptr){
                return false;
            }
            cur = cur->children[i]; //if exist
        }
        return cur->word == word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c:prefix){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
