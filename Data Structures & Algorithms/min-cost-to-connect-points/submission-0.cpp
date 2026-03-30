class Solution {
public:
  

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        int res = 0;
        int edgesConnected = 0;

        vector<int> min_dist(points.size(), INT_MAX);
        vector<bool> visited(points.size(), false);
    

        int curr = 0;
        min_dist[curr] = 0;

        while(edgesConnected < n){
            visited[curr] = true;
            res += min_dist[curr];
            edgesConnected++;

            int next_ = -1;
            int min_val = INT_MAX;
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    int d = abs(points[curr][0] - points[i][0]) + abs(points[curr][1] - points[i][1]);
                    min_dist[i] = min(min_dist[i], d); // to the group, instead of current node

                    if(min_dist[i] < min_val){
                        min_val = min_dist[i];
                        next_ =i;
                    }
                }
            }
            curr = next_;

        }

        
        return res;
    }
};
