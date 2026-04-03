class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int prev_not_hold = 0;
        int prev_hold = prices[0] * -1;
        
        for(int i=1; i<n; i++){
            int new_not_hold = max(prev_not_hold, prev_hold + prices[i]);
            int new_hold  = max(prev_hold, prev_not_hold - prices[i]); 

            prev_hold = new_hold;
            prev_not_hold = new_not_hold;

        }

        
        return prev_not_hold;
    }
};