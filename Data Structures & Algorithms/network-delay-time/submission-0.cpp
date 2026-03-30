class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> PII;
        vector<vector<PII>> adj( n + 1 );
        for(auto& t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> d(n+1, INT_MAX);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        d[k] = 0;
        pq.push({0, k});

        

        while(!pq.empty()){
          int curr_time = pq.top().first;
          int u = pq.top().second;
          pq.pop();

          if(curr_time >d[u]) continue;
          for(auto& edge: adj[u]){
            int v = edge.first;
            int weight = edge.second;
            if(d[u] + weight < d[v]){
                d[v] = d[u] + weight;
                pq.push({d[v], v});              
            }
          }

        }

        int res = 0;
        for(int i=1; i<=n; i++){
            if(d[i] == INT_MAX) return -1;
            res = max(res, d[i]);
        }


        return res;
    }
};
