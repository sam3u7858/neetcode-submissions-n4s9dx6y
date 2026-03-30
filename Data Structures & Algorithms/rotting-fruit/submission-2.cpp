class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int fresh_count = 0;
        int dir[4][2] = {
            {1,0},{0,1},{-1,0},{0,-1}
        };
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> bq;
        // add all the orange into the bqs

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    bq.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }

        while(!bq.empty() && fresh_count > 0){
            
            int size = bq.size();
            for(int r=0; r<size; r++){
                pair<int, int> curr = bq.front();
                bq.pop();

                int x = curr.first;
                int y = curr.second;

                for(const auto& d:dir){
                    int new_x = d[0] + x;
                    int new_y = d[1] + y;

                    if(new_x>=0 && new_y>=0 && new_x<rows && new_y<cols && grid[new_x][new_y] == 1){
                        bq.push({new_x, new_y});
                        grid[new_x][new_y] = 2;     
                        fresh_count -=1;
                    } 
                }
  
                
            }
            res+=1;
        }




        // Check, if there is still some unrotten orange after the diffuse
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return res;
    }
};
