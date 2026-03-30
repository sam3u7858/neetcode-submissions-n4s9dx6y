class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //NUMS(P) + NUMS(N) = total sum
        //NUMS(P) - NUMS(N) = target
        // (target + total_sum) / 2 = NUMS(P)
        // NUMS(N) = total_sum - NUMS(P);

        //if (target + total_sum )%2 != 0 : that means we cannot find a proper value to solve it.
    
        int sum = 0;
        for(const auto& i:nums){
            sum += i;
        }
        int check = (sum + target);
        if(check &1)return 0;
        check >>= 1; // since sum >0, target>0  and not==1, this always >0

        vector<int> dp(check+1, 0);
        dp[0] = 1;
        for(const auto& n:nums){
            for(int i=check; i>=n; i--){
                dp[i] += dp[i-n]; 
            }
        }
        // (1+x^nums[0])*(1+x^nums[1])*... and we find dp[target];


        return dp[check];
    
    }
};
