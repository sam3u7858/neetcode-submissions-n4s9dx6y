class Solution {
public:
    
    
    int directions[4][2] = {
            {1, 0},
            {0, 1},
            {0, -1},
            {-1, 0}
    };


    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string &word, int wordIndex, int x, int y){
        int row = board.size();
        int col = board[0].size();
        bool result = false;

        // Check if valid
        if( x<0 || y<0 || x>=row || y>=col || visited[x][y] == true || board[x][y]!=word[wordIndex]){
            return false;
        }

        // set flag
        visited[x][y] = true;

        // founded
        if(wordIndex == word.length()-1){
            return true;
        }

        for(auto &dir:directions){
            result = result || dfs(board, visited, word, wordIndex+1, x+dir[0], y+dir[1]);
            if(result){
                break;
            }
        }
        visited[x][y] = false;
        return result;


    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool res = false;


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = res || dfs(board, visited, word, 0, i, j);
                if(res == true){
                    return res;
                }
              
            }
        }

        return res;

    }
};
