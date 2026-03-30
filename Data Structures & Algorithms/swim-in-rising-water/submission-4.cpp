class Solution {
public:

    bool bfs(vector<vector<int>>& grid, int max){
        int n = grid.size();
        if (n == 1) return true; // 處理 1x1 的情況
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));


        if(grid[0][0] > max) return false;
        visited[0][0] = true;

        q.push({0,0});

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            pair<int ,int> curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            for(auto const& d: dirs){
                int new_x = x + d[0];
                int new_y = y + d[1];

                if(new_x >=0 && new_x<n && new_y>=0 && new_y<n && !visited[new_x][new_y] && grid[new_x][new_y] <= max){
                    if(new_x == n-1 && new_y == n-1) return true;
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }
        
        return false;

    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int max_in_grid = grid[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                max_in_grid = max(grid[i][j], max_in_grid);
            }
        }

        int low = grid[0][0];
        int high = max_in_grid;
        int res = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(bfs(grid, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }

        return res;

       
    }
};
