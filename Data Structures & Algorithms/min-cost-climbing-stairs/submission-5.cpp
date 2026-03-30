class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost should be 
        // goal = cost.size()
        // dp[goal] = (cost[i-1]+dp[i-1] , cost[i-2]+dp[i-2])
     
        int prev0 = 0;
        int prev1 = 0;

        for(int i=2; i<cost.size()+1; i++){
            
            int temp = min(cost[i-1]+prev1, cost[i-2]+prev0);
            prev0 = prev1;
            prev1 = temp;
        }

        return prev1;
    }
};
