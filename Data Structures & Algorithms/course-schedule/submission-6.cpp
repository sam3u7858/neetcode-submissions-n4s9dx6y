class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = numCourses;
        vector<vector<int>> adj(m);
        vector<int> indegree(m, 0);

        for(auto const& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for(int i=0; i<m; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            vector<int>& test = adj[curr];
            for(int i: test){
                indegree[i] -=1;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]!=0){
                return false;
            }
        }
        return true;


    }
};
