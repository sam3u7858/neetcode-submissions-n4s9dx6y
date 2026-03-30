class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(memo.find(amount) != memo.end()) return memo[amount];
        
        int res = INT_MAX;
        for(int coin : coins){
            if(amount - coin >= 0){
                int result = dfs(coins, amount - coin);
                if(result != INT_MAX){
                    res = min(res, 1+ result);
                }
            }
        }
        memo[amount] = res;
        return res;

    }

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount);
        if (res == INT_MAX) return -1;
        return res;
    }
};
