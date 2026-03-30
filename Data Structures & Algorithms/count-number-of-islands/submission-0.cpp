class Solution {
public:

    void bfs(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});

        grid[r][c] = '0';

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            pair<int, int> current = q.front();
            q.pop();

            for(auto& dir:directions){
                int new_r = current.first + dir[0];
                int new_c = current.second + dir[1];

                if(new_r>=0 && new_c>=0 && new_r < rows &&
                new_c < cols && grid[new_r][new_c] == '1'){

                    grid[new_r][new_c] = '0';
                    q.push({new_r, new_c});

                }

            }

        }

    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }

        int r = grid.size();
        int c = grid[0].size();
        int res = 0;

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j]=='1'){
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
