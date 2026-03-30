class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        vector<int> rest(n, 0);


        hold[0] = -1*prices[0];
        sold[0] = INT_MIN;
        rest[0] = 0;

        for(int i=1; i<n; i++){
          rest[i] = max(rest[i-1], sold[i-1]);
          hold[i] = max(rest[i-1]- prices[i], hold[i-1]);
          sold[i] = hold[i-1] + prices[i];
        }

        return max(rest[n-1],sold[n-1]);
    }
};
