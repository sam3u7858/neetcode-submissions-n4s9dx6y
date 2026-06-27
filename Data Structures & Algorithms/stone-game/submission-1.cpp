class Solution {
public:

    vector<vector<int>> dp;

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        int aliceScore = dfs(0, piles.size()-1, piles);
        return aliceScore > total - aliceScore;
    }

    int dfs(int l, int r, const vector<int>& piles){
        if(l > r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        bool even = (r - l) % 2 == 0;
        int left = even ? piles[l] : 0;
        int right = even ? piles[r] : 0;
        dp[l][r] = max(dfs(l+1, r, piles) + left ,dfs(l, r-1, piles)+right);
        return dp[l][r];
    }
};