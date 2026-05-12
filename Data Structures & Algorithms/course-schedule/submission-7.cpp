class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        int n = numCourses;
        for(auto const& curr:prerequisites){
            indegree[curr[0]]++;
            graph[curr[1]].push_back(curr[0]);
        }


        queue<int> q;
        for(int i=0; i<n; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front(); q.pop();
            vector<int>& adjs = graph[curr];
            for(const int& a:adjs){
                indegree[a] -= 1;
                if(indegree[a] == 0) q.push(a);
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i] != 0) {
                return false;
            }
            
        }

        return true;

        

    }
};
