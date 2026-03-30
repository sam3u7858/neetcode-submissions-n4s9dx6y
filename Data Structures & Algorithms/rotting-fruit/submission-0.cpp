class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int epoches = 0;

        queue<pair<int, int>> q;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }


        int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size = q.size();
            bool rottedAny = false;

            for(int i=0; i<size; i++){
                pair<int, int> curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(auto &d:direction){
                    int nx = d[0] + x;
                    int ny = d[1] + y;
                    if(nx>=0 && nx < row && ny>=0 && ny<col && grid[nx][ny] == 1){
                        //set the rotten
                        rottedAny = true;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }            

            }
            if(rottedAny) epoches++;
            
            
        }


         for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return epoches;
    }
};
