class Solution {
public:
    int rob(vector<int>& nums) { // robber ii

        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int prev1 = 0;
        int prev2 = 0;

        for(int i=static_cast<int>(nums.size())-1; i>=1; i--){
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;

        }
        int choice1 = prev1;

        prev1 = 0;
        prev2 = 0;

        for(int i=static_cast<int>(nums.size())-2; i>=0; i--){
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;

        }
        int choice2 = prev1;

        return max(choice1, choice2);
    }
};
