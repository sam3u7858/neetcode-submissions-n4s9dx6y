class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; 
        int n = nums.size();
        int res = INT_MAX;
        int currentSum = 0;

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        // prefix[i] - prefix[j] = sum of subarray

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
           
        }


        if(prefixSum[n-1] < target) return 0;

        for(int r=0; r<n; r++){
            currentSum = prefixSum[r] - prefixSum[l-1];
            
            while(currentSum >= target){
                currentSum -= nums[l];
                res = min(res, r-l+1);
                l++;
                
            }
            

        }


        return res;
    }
};