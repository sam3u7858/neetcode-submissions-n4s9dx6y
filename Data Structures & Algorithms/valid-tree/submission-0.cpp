class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<int>& path, int curr, int parent){
        if(path[curr] == 1) return false;
        if(path[curr] == 2) return true;

        vector<int> currAdj = adj[curr];

        bool res = true;
        path[curr] = 1;
        for(int i=0; i<currAdj.size(); i++){
            if(currAdj[i] != parent){
                res &= dfs(adj, path, currAdj[i], curr);
                if(res == false){
                    return false;
                }
            }
        }
        path[curr] = 2;
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size()>n-1 || edges.size()<n-1) return false;
      

        for(int i=0; i<edges.size(); i++){
            vector<int> curr = edges[i];
            adj[curr[0]].push_back(curr[1]);
            adj[curr[1]].push_back(curr[0]);
        }
        vector<int> path(n, 0);
        bool res = true;
        res &= dfs(adj, path, 0, -1);

        for(int i=0; i<path.size(); i++){
            if(path[i] != 2)return false;
        }

        return res;
        
        
    }
};
