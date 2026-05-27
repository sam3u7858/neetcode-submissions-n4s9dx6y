class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> b(n + 2, 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < n; i++) {
            b[i + 1] = nums[i];
        }

        // From len = 2, l=0, r=2
        // l starts from 0
        // r = l + len
        // we need (0, n+1)
        // n+1 - 0 +1 -> n+2 total so that's why dp is size n+2 from 0 to n+2
        // Ballons index from 1, to n

        // len 2-> r-l = 2
        // len 3-> r-l = 3
        // ...
        // len n -> r-l = n

        // for example[5,1,3]
        // we pad [1, 5, 1, 3, 1]
        // len = 2-> n-3(0),n-2(1),n-1(2),n(3),n+1(4)

        //[1,5,1], [5,1,3], [1,3,1]
        // start ->0~2 = len = 2-0 = 2
        // next -> 0~3 = len = 3-0 = 3
        // full leng-> 0~n+1 -> len = n+1-0
        // so the boundary is len<n+2

        // l+len -> r
        // to make r not out of bound-> r=n+1 (max)

        for (int len = 2; len < n + 2; len++) {
            for (int l = 0; l + len <= n + 1; l++) {
                int r = len + l;
                for (int i = l+1; i < r; i++) {
                    int gain = b[l] * b[i] * b[r];
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r] + gain);
                }
            }
        }

        return dp[0][n + 1];
    }
};
