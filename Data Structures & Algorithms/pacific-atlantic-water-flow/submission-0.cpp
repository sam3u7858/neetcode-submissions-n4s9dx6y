class Solution {
public:

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
    int row = heights.size();
    int col = heights[0].size();
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto& d : dir){
                int nx = x + d[0];
                int ny = y + d[1];
              
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && 
                !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return{};
        
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> fromPacificBool(row, vector<bool>(col, false));
        vector<vector<bool>> fromAtlanticBool(row, vector<bool>(col, false));

        queue<pair<int, int>> fromPacific;
        queue<pair<int, int>> fromAtlantic;

        // add source from pacific:
        for(int i=0; i<row; i++){
            fromPacific.push({i, 0});
            fromPacificBool[i][0] = true;
            fromAtlantic.push({i, col-1});
            fromAtlanticBool[i][col-1] = true;
        }

        for(int i=1; i<col; i++){
            fromPacific.push({0, i});
            fromPacificBool[0][i] = true;
            fromAtlantic.push({row-1, col-i-1});
            fromAtlanticBool[row-1][col-i-1] = true;
        }


        bfs(fromPacific, fromPacificBool, heights);
        bfs(fromAtlantic, fromAtlanticBool, heights);

        vector<vector<int>> res;

        for(int i = 0; i < row; i++){
            for(int j=0; j<col; j++){
                if(fromPacificBool[i][j] &&  fromAtlanticBool[i][j]){
                     res.push_back({i,j});
                }
            }
        }

        return res;

    }
};
