class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        if(nums.size()==1)return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
       

        for(int i=2; i<nums.size(); i++){
            int temp = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = temp;
           
       }

        return max(prev1, prev2);

    }
};
