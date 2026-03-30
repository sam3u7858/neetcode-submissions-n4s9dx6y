class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preCount(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            auto curr = prerequisites[i];
            preCount[curr[0]] +=1;
            adj[curr[1]].push_back(curr[0]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(preCount[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            vector<int> test = adj[curr];
            for(int i:test){
                preCount[i] -=1;
                if(preCount[i] == 0){
                    q.push(i);
                }
            }



        }

        for(int i=0; i<numCourses; i++){
            if(preCount[i]!=0){
                return false;
            }
        }
        return true;
        
        
        
    }
};
