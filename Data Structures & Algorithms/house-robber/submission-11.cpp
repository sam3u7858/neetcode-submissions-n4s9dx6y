class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0];

       
        int dp0 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            int current = max(dp1, nums[i]+dp0);
            dp0 = dp1;
            dp1 = current;
        }
        return dp1;
    }
};
