class Solution {
public:
    int robDPLinear(vector<int>& nums, int start, int end){
        if(nums.size()==1)return nums[0];

        int prev2 = 0;
        int prev1 = 0;
       

        for(int i=start; i<=end; i++){
            int temp = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = temp;
            
       }

        return max(prev1, prev2);
    }
    int rob(vector<int>& nums) {
        return max(robDPLinear(nums, 0, nums.size()-2), robDPLinear(nums, 1, nums.size()-1));
         
       

    }
};
