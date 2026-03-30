class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        int offset = 1;
        dp.push_back(0);
        
        if(n == 0)return {0};

        for(int i=1; i<=n; i++){
            if(offset*2 == i){
                offset = i;
            }

            dp.push_back( 1 + dp[i - offset]);
        }

        return dp;
    }
};
