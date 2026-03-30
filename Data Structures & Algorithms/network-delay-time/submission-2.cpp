class Node{
    public:
        int id;
        int dist;
        Node(int i, int d) : id(i), dist(d) {}

        bool operator>(const Node& other) const{
            return dist > other.dist;
        }

};

struct CompareNode{
    bool operator()(const Node& a, const Node& b){
        return a.dist > b.dist;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      int res=0;
      vector<vector<Node>> adj(n+1);
      for(int i=0; i<times.size(); i++){
        const vector<int> &curr = times[i];
        adj[curr[0]].push_back(Node(curr[1], curr[2]));
      }

      vector<int> d(n+1, INT_MAX);
      d[k] = 0;

      priority_queue<Node, vector<Node>, greater<Node>> pq;
      pq.push(Node(k, 0));

      while(!pq.empty()){
        Node curr = pq.top();
        int u = curr.id;
        pq.pop();

        if(curr.dist > d[u])continue;
        for(auto& edge:adj[u]){
            int v = edge.id;
            int weight = edge.dist;
            if(d[u] + weight < d[v]){

                d[v] = d[u] + weight;
                pq.push(Node(v, d[v]));
            }
        }
      }

      for(int i=1; i<=n; i++){
        if(d[i] == INT_MAX) return -1;
        res = max(d[i], res);
      }

      return res;
    }
};
