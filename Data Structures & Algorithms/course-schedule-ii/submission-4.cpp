class Solution {

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ordering;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (vector<int>& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> to_visit;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) to_visit.push(i);
        }
        while (!to_visit.empty()) {
            int current = to_visit.front(); to_visit.pop();
            ordering.push_back(current);
            for (int neighbour : graph[current]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) to_visit.push(neighbour);
            }
        }

        if (ordering.size() != numCourses) return {};
        return ordering;
    }
};
