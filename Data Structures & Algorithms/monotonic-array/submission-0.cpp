class Solution {
public:

    bool isIncreasing(vector<int>& nums){
        int n = nums.size();
        int last = nums[0];

        for(int i=1; i<n; i++){
            if(last > nums[i]) return false;
            last = nums[i];
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums){
        int n = nums.size();
        int last = nums[0];

        for(int i=1; i<n; i++){
            if(last < nums[i]) return false;
            last = nums[i];
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
       
       return isIncreasing(nums) || isDecreasing(nums);

        
    }
};