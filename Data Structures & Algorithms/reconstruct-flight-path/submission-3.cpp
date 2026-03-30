class Solution {
public:
    using TC = unordered_map<string, priority_queue<string, vector<string>, greater<string>>> ;
    TC adj;
    
    void dfs(string curr){
        while(adj.count(curr) && !adj[curr].empty()){
            string next = adj[curr].top();
            adj[curr].pop();
            dfs(next);
        }
        res.push_back(curr);

    }
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t:tickets){
            adj[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
