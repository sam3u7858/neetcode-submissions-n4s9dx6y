class Solution {
public:


    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int count_zero = 0;
        int res = 0;
        


        for(int r=0; r<nums.size(); r++){
            int curr = nums[r];
            if(curr == 0) count_zero++;


            if(count_zero > k){
                if(nums[l] == 0) count_zero--;
                l++;
            }

            res = max((r-l+1), res);


        }
        return res;
    }
};