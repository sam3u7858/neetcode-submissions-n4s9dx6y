class Solution {
public:
    int dfs(vector<int> &prices, int i, bool buying){

        // Base case
        if(i>=prices.size()){
            return 0;
        }


        int cooldown = dfs(prices, i+1, buying);
        // There are two situation:
        
        // You can buy (if not buying) or skip
        if(!buying){
            int buy = dfs(prices, i+1, true) - prices[i];
            return max(buy, cooldown);
        }

        // You can sell (if buying) or skip
        else{
            int sell = dfs(prices, i+2, false) + prices[i];
            return max(sell, cooldown);
        }


        
    }

    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, false);
    }
};
