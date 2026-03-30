class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        if(goal == 0)return true; //already in the goal O(1), means what is the smallest point to visit the goal
        for(int i=goal-1; i>=0; i--){
          
            if(nums[i] +i >= goal){
                goal = i;
            }
          

        }
        return goal == 0;
    }
};
