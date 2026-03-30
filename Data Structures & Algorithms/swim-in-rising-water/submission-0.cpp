struct Node{
    int height;
    int r,c;

    bool operator>(const Node& other) const{
        return height > other.height;
    }

};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int max_so_far = grid[0][0];
        
        while(!pq.empty()){
            Node curr = pq.top();
            pq.pop();

            max_so_far = max(max_so_far, curr.height);
            if(curr.r == n-1 && curr.c == n-1){
                return max_so_far;
            }

            for(const auto& d : dirs){
                int nr = curr.r + d[0];
                int nc = curr.c + d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }

        return max_so_far;

    }
};
