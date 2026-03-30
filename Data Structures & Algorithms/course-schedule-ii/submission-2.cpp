class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> res; 
        vector<vector<int>> adj(numCourses);    


        // res reserve
        res.reserve(numCourses);
        // add indegree and build adj list:
        for(auto& d:prerequisites){
            indegree[d[0]] += 1;
            adj[d[1]].push_back(d[0]);
        }

        // queue
        queue<int> zeroPrereq;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                zeroPrereq.push(i);
                // add to answer;
                res.push_back(i);
            }
        }

        while(!zeroPrereq.empty()){
            int index = zeroPrereq.front();
            zeroPrereq.pop();

            auto masters = adj[index];
            for(int i=0; i<masters.size(); i++){
                int masterIndex = masters[i];
                indegree[masterIndex] -=1;
                if(indegree[masterIndex] == 0){
                    zeroPrereq.push(masterIndex);
                    res.push_back(masterIndex);
                }
            }

        }
        if(res.size() != numCourses ) return {};
        return res;
        

    }
};
