 class DSU{
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1, 1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }

        }

        int find(int node){
            int cur = node;
            while(cur != parent[cur]){
                parent[cur] = parent[parent[cur]];
                cur = parent[cur];
            }
            return cur;
        }

        bool unionSets(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if(pu == pv){
                return false;
            }
            if(rank[pv] > rank[pu]){
                swap(pu, pv);
            }
            parent[pv] = pu;
            rank[pu] += rank[pv];
            return true;
        }
 };

class Solution {
public:
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // n-1+1;
        DSU dsu(n); 
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(!dsu.unionSets(u, v)){
                return edge;
            }
        }
        return {};


    }
};
