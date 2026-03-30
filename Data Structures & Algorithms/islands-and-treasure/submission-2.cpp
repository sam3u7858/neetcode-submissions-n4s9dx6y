class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int, int>> qe;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    qe.push({i,j});
                }
            }
        }

        int directions[4][2] = {{1, 0}, {-1,0}, {0, -1}, {0, 1}};
        // BFS
       
        while(!qe.empty()){
            pair<int, int> curr = qe.front();
            qe.pop();

            int x = curr.first;
            int y = curr.second;
            
            for(auto &d:directions){
                int nx = x + d[0];
                int ny = y + d[1];
                
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == INT_MAX){
                    grid[nx][ny] = grid[x][y] +1;
                    qe.push({nx, ny});

                }
            }

        }
        return;
    }
};
