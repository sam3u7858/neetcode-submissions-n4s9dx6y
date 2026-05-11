class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        int x = curr.first;
                        int y = curr.second;
                        grid[x][y] = '0';

                        for (auto const& d : dir) {
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '0') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
