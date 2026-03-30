class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;
        if(n == 0)return {0};

        for(int i=1; i<n+1; i++){
            if(i>=offset*2){
                offset = i;
            }
            dp[i] = 1+dp[i-offset];
        }

        return dp;
        

    }
};
