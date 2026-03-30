class Solution {
public:


    void dfs(vector<vector<int>> &adj, vector<bool>& check, int curr, int parent){
        if(check[curr]) return;
        check[curr] = true;
        auto& currAdj = adj[curr];
        for(int i=0; i<currAdj.size(); i++){
            if(currAdj[i] != parent){
                dfs(adj, check, currAdj[i], curr);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> check(n, false);
        int res = 0;
        for(int i=0; i<edges.size(); i++){
            vector<int> &curr = edges[i];
            adj[curr[0]].push_back(curr[1]);
            adj[curr[1]].push_back(curr[0]);
        }

       for(int i=0; i<n; i++){
            if(!check[i]){
                dfs(adj, check, i, -1);
                res +=1;
            }
       }
       return res;

    }
};
