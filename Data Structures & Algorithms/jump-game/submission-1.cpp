class Solution {
public:
    bool canJump(vector<int>& nums) {

        int goal = nums.size() - 1;
        if(goal == 0)return true; //already in the goal
        vector<bool> dp(goal, false);
        dp[goal] = true;
        for(int i=goal-1; i>=0; i--){
          
            if(nums[i] +i >= goal){
                
                goal = i;
                dp[goal] = true;
            }
          

        }
        return dp[0];
    }
};
