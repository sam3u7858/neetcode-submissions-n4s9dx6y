class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; 
        int n = nums.size();
        int res = INT_MAX;
        int currentSum = 0;

        for(int r=0; r<n; r++){
            currentSum += nums[r];
            
            while(currentSum >= target){
                res = min(res, r-l+1);
                currentSum -= nums[l];
        
                l++;
                
            }
            

        }

        if(res == INT_MAX)return 0;
        return res;
    }
};