class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int current = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(sum - current - nums[i] == current) return i;
            current += nums[i];
        }

        return -1;
    }
};