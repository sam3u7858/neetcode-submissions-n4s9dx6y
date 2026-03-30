class Solution {
public:
    // naive method (without DP) with startIndex, to calculate combinations instead of permuations

    vector<vector<int>> memo;

    int dfs(vector<int>& coins, int left, int startIndex){
        if(left == 0) return 1;
        if(startIndex >= coins.size()) return 0;

        if(memo[startIndex][left] != -1){
            return memo[startIndex][left];
        }

        int count = 0;
        for(int i=startIndex; i<coins.size(); i++){
            if (left-coins[i] < 0){
                continue;
            }
            count += dfs(coins, left-coins[i], i);
        }

        return memo[startIndex][left] = count;

    }
    int change(int amount, vector<int>& coins) {
        memo.assign(coins.size(), vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end());

    
        return dfs(coins, amount, 0);

    }
};
