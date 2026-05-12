class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);
        vector<int> res;

        for(auto const& p:prerequisites){
            indegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        



        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int curr = q.front(); q.pop();
            vector<int> curr_adj = adj[curr];
            for(const int& a:curr_adj){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                    res.push_back(a);
                }
            }
        }

        for(int i=0; i<n; ++i){
            if(indegree[i] != 0) return {};

        }


        return res;


    }
};
