class Solution {
    
public:
    inline bool checkVaild(vector<vector<int>>& grid, pair<int, int>& pos, int x, int y){
        int nx = pos.first + x;
        int ny = pos.second + y;
        int n = grid.size();
        int m = grid[0].size();
        return (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;

        // 1. Looking for all the rotten oranges
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        // 2. BFS using for loop
        while(!q.empty()){
            int queueSize = q.size();
            bool infect = false;
            for(int i=0; i<queueSize; i++){
                pair<int, int> curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;
                grid[x][y] = 2;
                for(auto const& d:dir){
                     if(checkVaild(grid, curr, d[0], d[1])){
                        q.push({d[0]+x, d[1]+y});
                        grid[d[0]+x][d[1]+y] = 2;
                        infect = true;
                     }
                }

            }

            if(infect)res++;
            


        }

        // 3. Check the board if all infect
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1) return -1;
            }
        }

        return res;

    }
};
