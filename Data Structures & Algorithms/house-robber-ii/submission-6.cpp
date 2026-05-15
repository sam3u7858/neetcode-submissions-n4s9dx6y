class Solution {
public:
    int getDPResult(vector<int>&nums, int starts, int end){
        if(nums.size()==0 ) return 0;
        if(nums.size()==1) return nums[0];
        if( end - starts < 1) return 0 ;
        int n = end;

        vector<int> dp(nums.size(), 0);
        dp[starts] = nums[starts];
        dp[starts+1] = max(nums[starts], nums[starts+1]);

        for(int i=starts+2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+ nums[i]);
        }

        return max(dp[end-1], dp[end-2] );
        


    }

    int rob(vector<int>& nums) {
        return max(getDPResult(nums, 0, nums.size()-1), getDPResult(nums, 1, nums.size()));
    }
};
