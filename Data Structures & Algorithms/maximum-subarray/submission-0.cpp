class Solution {
public:

    int getSubArrayMax(vector<int>& nums, int l, int r){
        // base case;
        if(l == r){
            return nums[l];
        }

        int mid = l + (r - l) / 2;
        int leftSideMax = getSubArrayMax(nums, l, mid);
        int rightSideMax = getSubArrayMax(nums, mid+1, r);

        // TODO:
        int currentLeftMax = INT_MIN;
        int currentRightMax = INT_MIN;
        // from mid to left
        
        int currentSum = 0;

        for(int i=mid; i>=l  ; i--){
            currentSum += nums[i];
            currentLeftMax = max(currentLeftMax, currentSum);
        }

        currentSum = 0;
         for(int i=mid+1; i<=r; i++){
            currentSum += nums[i];
            currentRightMax = max(currentRightMax, currentSum);
        }

        return max({leftSideMax, rightSideMax, currentRightMax+currentLeftMax});
        

    }

    int maxSubArray(vector<int>& nums) {
        return getSubArrayMax(nums, 0, nums.size()-1);
    }
};
