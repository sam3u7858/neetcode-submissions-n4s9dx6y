class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = 0;
        
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for(const auto &f:flights){
            adj[f[0]].push_back({f[1], f[2]});
  
        }

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        queue<int> bq;
        bq.push(src);

        
        

        while(!bq.empty() && k>=0){

            vector<int> nextPrices = prices;
            int sz = bq.size();
            for(int i=0; i<sz; i++){
                int curr = bq.front();
                bq.pop();

                auto adjPairs = adj[curr];
                for(const auto& v:adjPairs){
                    int price = v.second + prices[curr];
                    if(price < nextPrices[v.first]){
                        bq.push(v.first);
                        nextPrices[v.first] = min(price, prices[v.first]);
                    }
                   

                }
            }
            prices = nextPrices;
            k-=1;

        }

        if(prices[dst] == INT_MAX) return -1;
        return prices[dst];
    }
};
