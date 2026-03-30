class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();
        int maxSize = 1;

        queue<pair<int, int>> q;
        q.push({r,c});

        grid[r][c] = -1; // Visited

        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            pair<int, int> current = q.front();
            q.pop();

            for(auto& dir : directions){
                int n_r = current.first + dir[0];
                int n_c = current.second + dir[1];

                if(n_r>=0 && n_r < rows && n_c>=0 && n_c < cols
                   && grid[n_r][n_c] == 1){
                    grid[n_r][n_c] = -1;
                    maxSize += 1;
                    q.push({n_r, n_c});

                }
            }

        }
        return maxSize;



    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }

        int r = grid.size();
        int c = grid[0].size();
        int res = 0;

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){

                    int temp = bfs(grid, i, j);
                    cout << temp << "<<>> i:" << i << "j:" << j << endl; 
                    res = max(res, temp);
                }

            }
        }

        return res;
        
    }
};
