class Solution {
public:

    // recursion 
    int recursion(vector<int>& nums, int i, int prev, int maxLength){
        if(i == nums.size()) return maxLength;

        // select current or not
        int curr = nums[i];
        if(prev != INT_MIN){
            if(curr <= prev) {
                return recursion(nums, i+1, prev, maxLength);
            } // not valid, cannot add to the list.

            else{
                 int l1 = recursion(nums, i+1, prev, maxLength);
                 prev = curr;
                 int l2 = recursion(nums, i+1, prev, maxLength+1);
                 return max(l1, l2);
            }
        }

        else{ // The list is empty
            
            int l1 = recursion(nums, i+1, INT_MIN, maxLength); // not add
            prev = curr;
            int l2 = recursion(nums, i+1, prev, maxLength+1); // add current
            return max(l1, l2);

        }

    }


    int lengthOfLIS(vector<int>& nums) {
        
        int ans = recursion(nums, 0, INT_MIN, 0);
        return ans;
    }
};
