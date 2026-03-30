class Solution {
public:

    int directions[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

    vector<string> res;

    struct TrieNode{
        TrieNode* children[26];
        string word = ""; // For easier lookup.
        TrieNode(){
            for(int i=0; i<26; i++) children[i] = nullptr;
        }

        // Deconstructor - just in case!
        ~TrieNode(){
            for(int i = 0; i < 26; i++){
                if (children[i] != nullptr) {
                    delete children[i]; 
                }
            }
        }
    };

    void dfs(vector<vector<char>>& board, vector<string>& words, vector<vector<bool>> &visited, 
     TrieNode* currNode, int x, int y ){

        //TODO: 
        //1. Check the boundary
        int row = board.size();
        int col = board[0].size();
        if( x<0 || y<0 || x >= row || y >= col || visited[x][y] ){
            return;
        }

        //2. Check if current words[board[x][y]-'a'] has node, if not, return false for this line.
        char c = board[x][y];
        if(currNode->children[c - 'a'] != nullptr){
            currNode = currNode->children[c - 'a'];
            if(currNode->word != ""){
                res.push_back(currNode->word);
                currNode->word = "";
            }

        }
        else{
            return;
        }

        //3. set flag 'n' try dfs for 4 direction.
        visited[x][y] = true;
        //4. If the current  words[board[x][y]-'a']->word is not "", we add it to res and set back to "" , prevent from re-add of different path.
        for(auto &dir : directions){
            dfs(board, words, visited, currNode, x + dir[0], y + dir[1]);
        }
        //5. set back flag
        visited[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // 1. Create Trie Tree
        TrieNode* root = new TrieNode();
        for(string& s : words){
            TrieNode* p = root;
            for(char &c : s){
                if(!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode();
                p = p -> children[c - 'a'];
            }
            p->word = s;
        }
        // 2. DFS for words

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, words, visited, root, i, j);
            }
        }


        return res;

    }
};
