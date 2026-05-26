class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        vector<int> b(n+2, 1);

        for(int i=0; i<n; i++){
            b[i+1] = nums[i];
        }

        for(int len=2; len<=n+1; len++){
            for(int l=0; l+len<n+2; l++){
                int r = l + len;
                for(int i=l+1; i<r; i++){
                    int gain = b[l] * b[i] * b[r];
                    dp[l][r] = max(dp[l][r], dp[l][i]+dp[i][r]+gain);
                }
            }
        }
        return dp[0][n+1];
    }
};
