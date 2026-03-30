class Solution {
public:
    using ticketContainer = unordered_map<string, vector<string>>;
    bool dfs(ticketContainer &adj, vector<string> &path, string curr, int ticketCount){
        
        if(path.size() == ticketCount + 1){
            return true;
        }

        // NO TICKET
        if(adj.find(curr) == adj.end()) return false; 
        
        vector<string>& adjTicket = adj[curr];
            // backtracking + prune
        
        for(int i=0; i<adjTicket.size(); i++){
            string nextCurr = adjTicket[i];
            adjTicket.erase(adjTicket.begin()+i);
            path.push_back(nextCurr);

            if(dfs(adj, path, nextCurr, ticketCount)) return true;
            path.pop_back();
            adjTicket.insert(adjTicket.begin()+i, nextCurr);
           
        }
   
        return false;
 
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       //unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
       //using ticketContainer = unordered_map<string, priority_queue<string, vector<string>, greater<string>>>;
       ticketContainer adj;
       int ticketCount = tickets.size();
       
       for(const auto& t:tickets){
           adj[t[0]].push_back(t[1]);
       }

       for(auto &pair : adj){
            sort(pair.second.begin(), pair.second.end());
       }

       vector<string> path;
       path.push_back("JFK");
       
       //dfs to get all the routes
       dfs(adj, path, "JFK", ticketCount); // We start from "JKF"

       return path;
        
       // ticketContainer["name of airport"].

    
    }
};
