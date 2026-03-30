class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;


            //check 4 directions
            for(auto &d:directions){
                int nr = r+d[0];
                int nc = c+d[1];

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return;
        
    }
};
