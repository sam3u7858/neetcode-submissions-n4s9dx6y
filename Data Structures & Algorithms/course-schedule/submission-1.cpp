
class Solution {
public:
    bool dfs(vector<int> &path, vector<vector<int>>& adj, int curr){
        if(path[curr] == 1) return false;

        path[curr] = 1;
        bool res = true;

        auto a = adj[curr];
        for(int i=0; i<a.size(); i++){
            int pre = a[i];
            res &= dfs(path, adj, pre);
        }
        path[curr] = 0;
        return res;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 0 -> n; [a, b] a -> b
        // If cycled, impossible
        vector<vector<int>> adj(numCourses);    
        // build adj list:
        for(auto& edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }


        bool res = true;
        for(int i=0; i<numCourses; i++){
            vector<int> path(numCourses, 0);
            res &= dfs(path, adj, i);
        }

        return res;
    }
};
