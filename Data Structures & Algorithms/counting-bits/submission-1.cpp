class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        int offset = 2;
        dp.push_back(0);
        dp.push_back(1);

        if(n==0){
            return {0};
        }
        if(n==1){
            return{0,1};
        }

        for(int i=2; i<=n; i++){
            if(offset*2 == i){
                offset = i;
            }
            dp.push_back( dp[i-offset] +1);
          
            
            
        }

        return dp;
 
    }
};
