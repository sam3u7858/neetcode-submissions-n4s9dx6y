class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> qe;

        // Get Rotting
        for(int i = 0; i < row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    qe.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        
        // MPBFS
        int epoch = 0;
        

        while(!qe.empty()){
            int size = qe.size();
          
            

            bool rotten = false;
            for(int i = 0; i<size; i++){

                pair<int,int> curr = qe.front();
                qe.pop();

                int x = curr.first;
                int y = curr.second;

                for(auto &d:dir){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx < row && ny >=0 && ny < col && grid[nx][ny] == 1 ){
                            qe.push({nx, ny});
                            rotten = true;
                            grid[nx][ny] = 2; // rotten
        
                    }  
                }
            }

            if(rotten) epoch +=1;
            

        }

         for(int i = 0; i < row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return epoch;


    }
};
