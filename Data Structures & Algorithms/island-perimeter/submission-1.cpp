    class Solution {
    public:

        pair<int, int> getFirstPoint(vector<vector<int>>& grid){
            int n = grid.size();
            int m = grid[0].size();
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1){
                        
                        return {i, j};

                    }
                }
            }
            return {-1, -1};
        }
        int islandPerimeter(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int size = 0;

            int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            queue<pair<int, int>> pq;

            pq.push(getFirstPoint(grid));
            


            int perimeter = 0;

            while(!pq.empty()){
                pair<int, int> curr = pq.front();
                pq.pop();
                size += 1;
                grid[curr.first][curr.second] = -1;
                
                for(auto const &d:dir){
                    int nx = curr.first + d[0];
                    int ny = curr.second + d[1];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        perimeter++;
                    }
                    else if (grid[nx][ny] == 0) {
                        perimeter++;
                    }

                    else if (grid[nx][ny] == 1) {
                        grid[nx][ny] = -1; 
                        pq.push({nx, ny});
                    }
                }


            }
            
            

            return perimeter;
        }
    };