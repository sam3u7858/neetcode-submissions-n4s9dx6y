class Solution {
public:

    // recursion 
    int recursion(vector<int>& nums, int i, vector<int> list, int maxLength){
        if(i == nums.size()) return maxLength;

        // select current or not
        int curr = nums[i];
        if(!(list.empty())){
            if(curr <= list.back()) {
                return recursion(nums, i+1, list, maxLength);
            } // not valid, cannot add to the list.

            else{
                 int l1 = recursion(nums, i+1, list, maxLength);
                 list.push_back(nums[i]);
                 int l2 = recursion(nums, i+1, list, maxLength+1);
                 return max(l1, l2);
            }
        }

        else{ // The list is empty

            int l1 = recursion(nums, i+1, list, maxLength); // not add
            list.push_back(nums[i]);
            int l2 = recursion(nums, i+1, list, maxLength+1); // add current
            return max(l1, l2);

        }

    }


    int lengthOfLIS(vector<int>& nums) {
        
        int ans = recursion(nums, 0, {}, 0);
        return ans;
    }
};
