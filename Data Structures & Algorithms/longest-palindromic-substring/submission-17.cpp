class Solution {
public:
    string longestPalindrome(string s){
        int n = s.length();
        if(n<2) return s;
        int start = 0;
        int maxLen = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            // len == 1;
            dp[i][i] = true;
            
            // len == 2;
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }

        
        }
      
        for(int len=3; len<=n; len++){
            for(int l=0; l + len - 1 < n; l++){
                int r = l + len - 1;
                if(s[l] == s[r]){
                    dp[l][r] = dp[l+1][r-1];
                }

                if(dp[l][r] && len > maxLen){
                    maxLen = len;
                    start = l;
                }
            }
        }

        return s.substr(start, maxLen);

        
        


    }
};
