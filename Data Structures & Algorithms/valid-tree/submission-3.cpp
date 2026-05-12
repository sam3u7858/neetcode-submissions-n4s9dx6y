class Solution {
public:
    int find(vector<int>& parent, int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto& edge : edges){

            int root1 = find(parent, edge[0]);
            int root2 = find(parent, edge[1]);

            if(root1 == root2){
                return false;
            }

            parent[root1] = root2;



        }



        return true;



    }
};
