class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size();
        int m = s2.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        for(int j=1; j<=m; j++){
            if(dp[0][j-1] && s2[j-1] == s3[j-1]){
                dp[0][j] = true;
            }
        }

        for(int i=1; i<=n; i++){
            if(dp[i-1][0] && s1[i-1] == s3[i-1]){
                dp[i][0] = true;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // take s1
                if(dp[i-1][j] && s1[i-1] == s3[i+j-1] ||  dp[i][j-1] && s2[j-1] == s3[i+j-1]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }

            }
        }


        return dp[n][m];
    }
};
