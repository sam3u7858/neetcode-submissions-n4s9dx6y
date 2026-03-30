class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int x, int y, int row, int col){
        if(x>=row || x<0 || y>=col || y<0 || board[x][y] == '#' || board[x][y] == 'X')return;
        
        board[x][y] = '#';
        for(auto &d:dir){
            int nx = x + d[0];
            int ny = y + d[1];
            
            dfs(board, nx, ny, row, col);
        }

    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<pair<int, int>> bordor_O;
        for(int i = 0; i<row; i++){
            if(board[i][0] == 'O')bordor_O.push_back({i, 0});
            if(board[i][col-1] == 'O') bordor_O.push_back({i, col-1});
        }
        for(int i = 1; i<col-1; i++){
            if(board[0][i] == 'O')bordor_O.push_back({0, i});
            if(board[row-1][i] == 'O') bordor_O.push_back({row-1, i});
        }

        cout << "herer";

        for(auto &p:bordor_O){
            dfs(board, p.first, p.second, row, col);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }

        return;

    }
};
