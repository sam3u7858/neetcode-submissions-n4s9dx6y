class TrieNode{
public:
    TrieNode* children[26];
    string word = ""; // For lookup in the future

    TrieNode(){
        for(int i=0; i<26; i++)children[i] = nullptr;
    }

    ~TrieNode(){
        for(int i=0; i<26; i++){
            delete children[i];
        }
    } 
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->word = word;
        return;
    }
    
    bool helper(string& word, int index, TrieNode* node){
        TrieNode* curr = node;
        for(int i=index; i<word.length(); i++){
            char c = word[i];
            int j = c - 'a';
            
            if(c == '.'){
                bool result = false;
                for(int k=0; k<26; k++){ // from a to z
                    if(curr->children[k] != nullptr) {
                    if(helper(word, i + 1, curr->children[k])) return true;
                }
                }
                return result;
            }

            if(curr->children[j] == nullptr){
                return false;
            }
            curr = curr->children[j];
        }

        return curr->word != "";
    }

    bool search(string word) {
    return helper(word, 0, root);
    }
};
