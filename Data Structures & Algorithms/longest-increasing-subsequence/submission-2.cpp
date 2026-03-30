class Solution {
public:

    // recursion 
    int recursion(vector<int>& nums, int i, int prev, int maxLength){
        if(i == nums.size()) return maxLength;

        int curr = nums[i];
        if (curr > prev){ // able to pick
            int l1 = recursion(nums, i+1, prev, maxLength);
            int l2 = recursion(nums, i+1, curr, maxLength + 1);
            return max(l1, l2);
        }
        else{
            return recursion(nums, i+1, prev, maxLength);
        }

    }


    int lengthOfLIS(vector<int>& nums) {
        
        int ans = recursion(nums, 0, INT_MIN, 0);
        return ans;
    }
};
